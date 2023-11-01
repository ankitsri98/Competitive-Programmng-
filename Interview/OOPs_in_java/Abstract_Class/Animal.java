package com.personal.oops;

//This is a Abstract class 
public abstract class Animal {

    int age;
    String gender;
    int weightInlbs;

    public Animal(int age, String gender, int weightInlbs) {
        this.age = age;
        this.gender = gender;
        this.weightInlbs = weightInlbs;
    }

    public void eat() {
        System.out.println("Eating...");
    }

    public void sleep() {
        System.out.println("sleeping...");
    }
    //Here is the abstract method
    public abstract void move();
}
