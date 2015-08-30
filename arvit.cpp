#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
   while (true) {
      int n, units = 0;
      cin >> n;
      if (n == 0)
         break;
      // first: index, second: value
      vector<pair<int, int> > sellers, consumers;
      for (int i = 0; i < n; i++) {
         int person;
         cin >> person;
         // Seller
         if (person < 0) {
            sellers.push_back(make_pair(i, -person));
            bool stop = false;
            int sellInd = sellers.size() - 1;
            while (!stop && !consumers.empty()) {
               int consInd = consumers.size() - 1;
               if (sellers[sellInd].second < consumers[consInd].second) {
                  units += (sellers[sellInd].second * abs(
                        i - consumers[consInd].first));
                  consumers[consInd].second -= sellers[sellInd].second;
                  sellers.pop_back();
                  stop = true;
               } else if (sellers[sellInd].second
                     > consumers[consInd].second) {
                  units += (consumers[consInd].second * abs(
                        i - consumers[consInd].first));
                  sellers[sellInd].second -= consumers[consInd].second;
                  consumers.pop_back();
               } else {
                  units += (consumers[consInd].second * abs(
                        i - consumers[consInd].first));
                  consumers.pop_back();
                  sellers.pop_back();
                  stop = true;
               }
            }
         }
         // Consumer
         else if (person > 0) {
            consumers.push_back(make_pair(i, person));
            bool stop = false;
            int consInd = consumers.size() - 1;
            while (!stop && !sellers.empty()) {
               int sellInd = sellers.size() - 1;
               if (sellers[sellInd].second < consumers[consInd].second) {
                  units += (sellers[sellInd].second * abs(
                        i - sellers[sellInd].first));
                  consumers[consInd].second -= sellers[sellInd].second;
                  sellers.pop_back();
               } else if (sellers[sellInd].second
                     > consumers[consInd].second) {
                  units += (consumers[consInd].second * abs(
                        i - sellers[sellInd].first));
                  sellers[sellInd].second -= consumers[consInd].second;
                  consumers.pop_back();
                  stop = true;
               } else {
                  units += (consumers[consInd].second * abs(
                        i - sellers[sellInd].first));
                  consumers.pop_back();
                  sellers.pop_back();
                  stop = true;
               }
            }
         }
      }
      cout << units << endl;
   }
   return 0;
}
