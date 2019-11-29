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
            hashSet.add(i);
        }
    }

    @Override
    public void FindTest() {
        Integer toFind = hashSet.size() - 1;
        for (int i = 0; i < numOfOperations; i++) {
            boolean result = hashSet.contains(toFind);
        }
    }

    @Override
    public void RemoveTest() {
        Integer toRemove = hashSet.size() - 1;
        for (int i = 0; i < numOfOperations; i++) {
            hashSet.remove(toRemove);
            toRemove--;
        }
    }
}
