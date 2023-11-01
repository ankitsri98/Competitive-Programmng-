package com.personal.oops;

public class Fish extends Animal {

    //Remember that the base and child class should have the same way of creating object like parameterised constructor here.
    public Fish(int age, String gender, int weightInlbs) {
        super(age, gender, weightInlbs);
    }

    public void move() {
        System.out.println("Fish move by swimming...");
    }

    public void swim() {
        System.out.println("swimming...");
    }
}
