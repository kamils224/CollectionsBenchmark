package com.company;

import java.util.HashSet;

public class HashSetTest implements IBenchmark {

    HashSet<Integer> hashSet;
    int numOfOperations;

    public HashSetTest(){
        hashSet = new HashSet<>();
        this.numOfOperations = 100;
    }

    public HashSetTest(int numOfOperations){
        hashSet = new HashSet<>();
        this.numOfOperations = numOfOperations;
    }

    @Override
    public void AddTest() {
        for (int i = 0; i < numOfOperations; i++) {
            Integer toAdd = hashSet.size();
            hashSet.add(toAdd);
        }
    }

    @Override
    public void FindTest() {
        for (int i = 0; i < numOfOperations; i++) {
            Integer toFind = hashSet.size() - 1;
            boolean result = hashSet.contains(toFind);
        }
    }

    @Override
    public void RemoveTest() {
        for (int i = 0; i < numOfOperations; i++) {
            Integer toRemove = hashSet.size() - 1;
            hashSet.remove(toRemove);
        }
    }
}
