    /* Part of Cosmos by OpenGenus Foundation */
    #include<iostream>
    using namespace std;
    /*
    *Find whether or not there exists any subset 
    *  of array  that sum up to targetSum
    */
    class Subset_Sum
    {
        public:
        // BACKTRACKING ALGORITHM
        void subsetsum_Backtracking(int Set[] , int pos, int sum, int tmpsum, int size, bool & found)
        {
            if (sum == tmpsum)
                found = true;
                // generate nodes along the breadth
            for (int i = pos; i < size; i++)
            {
             if (tmpsum + Set[i] <= sum)
               {
                  tmpsum += Set[i];   
                  // consider next level node (along depth)
                  subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
                  tmpsum -= Set[i];
                }
            }
        }
    };
    
    int main()
    {
        int i, n, sum;
        Subset_Sum S;
        cout << "Enter the number of elements in the set" << endl;
        cin >> n;
        int a[n];
        cout << "Enter the values" << endl;
        for(i=0;i<n;i++)
          cin>>a[i];
        cout << "Enter the value of sum" << endl;
        cin >> sum;
        bool f = false;
        S.subsetsum_Backtracking(a, 0, sum, 0, n, f);
        if (f)
           cout << "subset with the given sum found" << endl;
        else
           cout << "no required subset found" << endl;   
        return 0;
    }
