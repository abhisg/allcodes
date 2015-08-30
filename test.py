s = "ADOBECODEBANC"
t = "ABC"
if len(s) >= len(t):

            cutoffcount = {}

            for c in t:

                if c in cutoffcount:

                    cutoffcount[c] = cutoffcount[c] + 1

                else:

                    cutfoffcount[c] = 1

            currentcount = {}

            for c in cutoffcount:

                currentcount[c] = 0

            minpair = (0,len(s))

            (i,j) = (0,0)

            modif = False

            if s[0] in cutoffcount:

                currentcount[s[0]] = currentcount[s[0]] + 1

            while i < len(s) and j < len(s):

                suffcount = True

                for c in cutoffcount:

                    if currentcount[c] < cutoffcount[c]:

                        suffcount = False

                        break

                if suffcount == True:

                    print (i+1,j)

                    modif = True

                    if j+1-i < minpair[1] - minpair[0]:

                        minpair = (i,j+1)

                    if s[i] in currentcount:

                        currentcount[s[i]] = currentcount[s[i]] - 1

                    i = i + 1

                else:

                    j = j + 1

                    if j < len(s) and s[j] in cutoffcount:

                        currentcount[s[j]] = currentcount[s[j]] + 1

            if modif == True:

                print s[minpair[0],minpair[1]+1]

            else:

                print ""

        else:

            print ""
