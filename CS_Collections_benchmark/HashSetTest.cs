using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Collections_benchmark
{
    class HashSetTest : IBenchmark
    {
        HashSet<int> hashSet;
        int numOfOperations;
        public HashSetTest()
        {
            hashSet = new HashSet<int>();
            numOfOperations = 100;
        }

        public HashSetTest(int numOfOperations)
        {
            hashSet = new HashSet<int>();
            this.numOfOperations = numOfOperations;
        }


        public void AddTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                hashSet.Add(i);
            }
        }

        public void FindTest()
        {
            int toFind = hashSet.Count - 1;
            for (int i = 0; i < numOfOperations; i++)
            {
                bool result = hashSet.Contains(toFind);
            }
        }

        public void RemoveTest()
        {
            int toRemove = hashSet.Count - 1;
            for (int i = 0; i < numOfOperations; i++)
            {
                hashSet.Remove(toRemove);
                toRemove--;
            }

        }
    }
}
