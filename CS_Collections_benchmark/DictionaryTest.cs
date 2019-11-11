using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Collections_benchmark
{
    class DictionaryTest : IBenchmark
    {
        Dictionary<int, int> dictionary;
        int numOfOperations;
        public DictionaryTest()
        {
            dictionary = new Dictionary<int, int>();
            this.numOfOperations = 100;
        }
        public DictionaryTest(int numOfOperations)
        {
            dictionary = new Dictionary<int, int>();
            this.numOfOperations = numOfOperations;
        }

        public void AddTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                int toAdd = dictionary.Count;
                dictionary.Add(toAdd, toAdd);
            }

        }

        public void FindTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                int value = dictionary.Count - 1;
                bool result = dictionary.ContainsValue(value);
            }
        }

        public void RemoveTest()
        {
            for (int i = 0; i < numOfOperations; i++)
            {
                int toRemove = dictionary.Count - 1;
                dictionary.Remove(toRemove);
            }
        }
    }
}
