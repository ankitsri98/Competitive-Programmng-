package com.personal.oops;

public class Human {

    /*
    CLASSES carry instructions on how OBJECTS can be "created" and how they "behave".
     */
    String name;
    int age;
    int heightInInches;
    String eyeColour;

    //Below is the method which helps in creating Objects of this class
    //It's a constructor : does not have a return type : have same name as that of class

    //parametrised constructor
    //This keyword refers to the instance variable "tom" in main class : Earth
    public Human(String name, int age, int heightInInches, String eyeColour) {
        this.name = name;
        this.age = age;
        this.heightInInches = heightInInches;
        this.eyeColour = eyeColour;
    }

    //Below are the properties how this class will behave
    public void speak() {
        System.out.println("Hello, my name is: "+ name);
        System.out.println("Hello, my age is: "+ age);
        System.out.println("Hello, my eyeColour is: "+ eyeColour);
        System.out.println("Hello, my height is: "+ heightInInches);
    }

    public void eat() {
        System.out.println("eating.....");
    }

    public void walk() {
        System.out.println("walking.....");
    }

    public void working() {
        System.out.println("working.....");
    }
}
