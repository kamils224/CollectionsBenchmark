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
                int toAdd = hashSet.Count;
                hashSet.Add(toAdd);
            }
        }

        public void FindTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                int toFind = hashSet.Count - 1;
                bool result = hashSet.Contains(toFind);
            }
        }

        public void RemoveTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                int toRemove = hashSet.Count - 1;
                hashSet.Remove(toRemove);
            }

        }
    }
}
