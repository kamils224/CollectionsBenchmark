using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Collections_benchmark
{
    class ListTest : IBenchmark
    {
        List<int> list;
        int numOfOperations;

        public ListTest()
        {
            list = new List<int>();
            numOfOperations = 100;
        }

        public ListTest(int numOfOperations)
        {
            list = new List<int>();
            this.numOfOperations = numOfOperations;
        }

        public void AddTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                list.Add(i);
            }
        }

        public void FindTest()
        {
            int toFind = list[list.Count - 1];
            for (int i = 0; i < numOfOperations; i++)
            {
                int foundElement = list.Find(x => x == toFind);
            }
        }

        public void RemoveTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                int toRemove = list[0];
                list.Remove(toRemove);
            }
        }
    }
}
