package com.company;

import java.util.HashMap;

public class HashMapTest implements IBenchmark {

    HashMap<Integer, Integer> map;
    int numOfOperations;

    public HashMapTest(){

        map = new HashMap<>();
        this.numOfOperations = 100;
    }

    public HashMapTest(int numOfOperations){
        map = new HashMap<>();
        this.numOfOperations = numOfOperations;
    }


    @Override
    public void AddTest() {

        for (int i = 0; i < numOfOperations ; i++) {
            map.put(i, i);
        }
    }

    @Override
    public void FindTest() {
        Integer toFind = map.size()-1;
        for (int i = 0; i < numOfOperations; i++){
            boolean result = map.containsValue(toFind);
        }
    }

    @Override
    public void RemoveTest() {
        Integer toRemove = map.size()-1;
        for (int i = 0; i < numOfOperations; i++) {
            map.remove(toRemove);
            toRemove--;
        }
    }
}
