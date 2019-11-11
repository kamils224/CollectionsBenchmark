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
            Integer toAdd = map.size();
            map.put(toAdd, toAdd);
        }
    }

    @Override
    public void FindTest() {

        for (int i = 0; i < numOfOperations; i++){
            Integer toFind = map.size()-1;
            boolean result = map.containsValue(toFind);
        }

    }

    @Override
    public void RemoveTest() {

        for (int i = 0; i < numOfOperations; i++) {
            Integer toRemove = map.size()-1;
            map.remove(toRemove);
        }
    }
}
