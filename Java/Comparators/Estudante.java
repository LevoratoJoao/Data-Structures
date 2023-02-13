package Java.Comparators;

public class Estudante implements Comparable<Estudante> { //implements keyword is used to implement an interface . The interface keyword is used to declare a special type of class that only contains abstract methods.
    private final String name;
    private final Integer age;

    public Estudante(String name, Integer age) {
        this.name = name;
        this.age = age;
    }
    public String getName() { return name; }
    public Integer getAge() { return age; }

    @Override
    public String toString() { return name + ": " + age; }

    @Override //the child class method is over-writing its base class method.
    public int compareTo(Estudante o) {
        return this.getAge() - o.getAge();
    }
}
