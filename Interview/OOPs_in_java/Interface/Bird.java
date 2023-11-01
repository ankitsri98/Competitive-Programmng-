package com.personal.oops;

public class Bird extends Animal {

    public Bird(int age, String gender, int weightInlbs) {
        super(age, gender, weightInlbs);
    }

    public void fly() {
        System.out.println("flying...");
    }
}
