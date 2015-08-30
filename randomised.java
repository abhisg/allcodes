import java.io.*;
import java.util.*;

class randomised
{
	static int mergeSort(double[] ar,int l,int h)
	{
		if(l>=h || l==h-1)
			return 0;
		int mid=(h-l)/2+l;
		int x=mergeSort(ar,l,mid);
		int y=mergeSort(ar,mid,h);
		int count=x+y;
		double[] temp=new double[h-l];
		int i,pt=0,j=l,k=mid;
		for(i=l;i<h;i++)
		{
			if(j<mid && k<h)
			{
				if(ar[j]<=ar[k])
					temp[pt++]=ar[j++];
				else
					temp[pt++]=ar[k++];
				count++;
			}
			else if(j<mid)
				temp[pt++]=ar[j++];
			else
				temp[pt++]=ar[k++];
		}
		for(i=l;i<h;i++)
			ar[i]=temp[i-l];
		return count;
	}	

	static int normalQuickSort(double[] ar,int l,int h)
	{
		if(l>=h-1)
			return 0;
		int offset=(h-l)/2;
		double pivot=ar[l+offset];
		ar[l+offset]=ar[h-1];
		ar[h-1]=pivot;
		int i,ptr=l;
		for(i=l;i<h-1;i++)
		{
			if(ar[i]<=pivot)
			{
				double temp=ar[ptr];
				ar[ptr]=ar[i];
				ar[i]=temp;
				ptr++;
			}
		}
		double temp=ar[ptr];
		ar[ptr]=ar[h-1];
		ar[h-1]=temp;
		return normalQuickSort(ar,l,ptr)+normalQuickSort(ar,ptr+1,h)+(h-l-1);
	}

	static int randomQuickSort(double[] ar,int l,int h,Random rnd)
	{
		if(l>=h-1)
			return 0;
		int offset=rnd.nextInt(h-l);
		double pivot=ar[l+offset];
		ar[l+offset]=ar[h-1];
		ar[h-1]=pivot;
		int i,ptr=l;
		for(i=l;i<h-1;i++)
		{
			if(ar[i]<=pivot)
			{
				double temp=ar[ptr];
				ar[ptr]=ar[i];
				ar[i]=temp;
				ptr++;
			}
		}
		double temp=ar[ptr];
		ar[ptr]=ar[h-1];
		ar[h-1]=temp;
		return randomQuickSort(ar,l,ptr,rnd)+randomQuickSort(ar,ptr+1,h,rnd)+(h-l-1);
	}
	
	static void part1()
	{
		int instances[]={100,1000,10000,100000,1000000};
		int i,j,k;
		System.out.println("----------Randomised quick sort outputs----------");
		System.out.print("N\tRuntime\tDoubleRunTime\tRuntimeComp\n");
		for(i=0;i<5;i++)
		{
			double runtime=0,doublerun=0,val1=0;	
			double[] ar;
			ar=new double[instances[i]];
			Random rand = new Random();
			for(k=0;k<instances[i];k++)
				ar[k]=rand.nextDouble();
			for(j=0;j<1000;j++)
			{
				long t1,t2;
				t1=System.nanoTime();
				val1+=randomQuickSort(ar,0,instances[i],rand);
				t2=System.nanoTime();
				double tmp=((double)t2-(double)t1)/1000;
				runtime+=tmp;
				t1=System.nanoTime();
				int val2=randomQuickSort(ar,0,instances[i],rand);
				t2=System.nanoTime();
				doublerun+=tmp+((double)t2 - (double)t1)/1000; 
			}
			System.out.println(instances[i]+"\t"+runtime/1000+"\t"+doublerun/1000+"\t"+val1/1000);
		}
		System.out.println("--------------------------------------------------------");
		System.out.println("-----------------Normal quick sort outputs--------------");
		System.out.print("N\tRuntime\tDoubleRunTime\tRuntimeComp\n");
		for(i=0;i<5;i++)
		{
			double runtime=0,doublerun=0,val1=0;	
			double[] ar;
			ar=new double[instances[i]];
			for(j=0;j<1000;j++)
			{
				Random rand = new Random();
				for(k=0;k<instances[i];k++)
					ar[k]=rand.nextDouble();
				long t1,t2;
				t1=System.nanoTime();
				val1+=normalQuickSort(ar,0,instances[i]);
				t2=System.nanoTime();
				double tmp=((double)t2-(double)t1)/1000;
				runtime+=tmp;
				t1=System.nanoTime();
				int val2=normalQuickSort(ar,0,instances[i]);
				t2=System.nanoTime();
				doublerun+=tmp+((double)t2 - (double)t1)/1000; 
			}
			System.out.println(instances[i]+"\t"+runtime/1000+"\t"+doublerun/1000+"\t"+val1/1000);
		}
	}
	
	static void part2()
	{
		int instances[]={100,1000,10000,100000,1000000};
		int i,j,k;
		System.out.println("N \t Quicksort runtime \t Quicksort comparison \t MergeSort runtime \t Quicksort runtime \t Mergesort_better \t Quicksort_better");
		for(i=0;i<5;i++)
		{
			double runtime_quicksort=0,val1_quicksort=0,runtime_mergesort=0,val1_mergesort=0,comp=0;	
			double[] ar1,ar2;
			ar1=new double[instances[i]];
			ar2=new double[instances[i]];
			for(j=0;j<1000;j++)
			{
				Random rand = new Random();
				for(k=0;k<instances[i];k++)
				{
					double num=rand.nextDouble();
					ar1[k]=num;
					ar2[k]=num;
				}
				long t1_quick,t2_quick,t1_merge,t2_merge;

				t1_quick=System.nanoTime();
				val1_quicksort+=normalQuickSort(ar1,0,instances[i]);
				t2_quick=System.nanoTime();
				runtime_quicksort+=((double)t2_quick-(double)t1_quick)/1000;

				t1_merge=System.nanoTime();
				val1_mergesort+=mergeSort(ar2,0,instances[i]);
				t2_merge=System.nanoTime();
				runtime_mergesort+=((double)t2_merge - (double)t1_merge)/1000;

				if(t2_merge-t1_merge < t2_quick-t1_quick)
					comp++;
			}
			System.out.println(instances[i]+"\t"+runtime_quicksort/1000+"\t"+val1_quicksort/1000+"\t"+runtime_mergesort/1000+"\t"+val1_mergesort/1000+"\t"+comp+"\t"+(1000-comp));
		}
	}
	
	static void part3()
	{
		int instances[]={100,1000,10000,100000,1000000};
			int i,j,k;
			for(i=0;i<5;i++)
			{
				double runtime_quicksort=0,val1_quicksort=0;	
				double[] ar;
				ar=new double[instances[i]];
				for(j=0;j<1000;j++)
				{
					Random rand = new Random();
					for(k=0;k<instances[i];k++)
					{
						double num=rand.nextDouble();
						ar[k]=rand.nextDouble();
					}
					long t1_quick,t2_quick;
					double v1,v2;
					t1_quick=System.nanoTime();
					v1=normalQuickSort(ar,0,instances[i]);
					val1_quicksort+=v1;
					t2_quick=System.nanoTime();
					v2=((double)t2_quick-(double)t1_quick)/1000;
					runtime_quicksort+=v2;
					System.out.println(instances[i]+","+v1+","+v2);
				}
				System.out.println("remove"+instances[i]+"\t"+runtime_quicksort/1000+"\t"+val1_quicksort/1000);
			}
	}
	
	public static void main(String args[]) throws IOException
	{
		part3();
	}
}
	
