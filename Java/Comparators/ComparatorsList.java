package Java.Comparators;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ComparatorsList {
    public static void main(String[] args) {
        List<Estudante> students = new ArrayList<>();

        students.add(new Estudante("Joao", 21));
        students.add(new Estudante("Maria", 18));
        students.add(new Estudante("Ramon", 20));
        students.add(new Estudante("Ana", 20));
        students.add(new Estudante("Gabriel", 33));
        students.add(new Estudante("Nathalia", 17));
        students.add(new Estudante("Caio", 19));
        System.out.println("\nInsert: " + students);

        students.sort((first, second) -> first.getAge() - second.getAge());
        System.out.println("\nIn order (lambda sort): " + students);

        students.sort((first, second) -> second.getAge() - first.getAge());
        System.out.println("\nReverse order (lambda sort): " + students);

        students.sort(Comparator.comparingInt(Estudante::getAge));
        System.out.println("\nIn order (method reference): " + students);

        students.sort(Comparator.comparingInt(Estudante::getAge).reversed());
        System.out.println("\nReverse order (method reference): " + students);
        Collections.sort(students);

        System.out.println("\nIn order (interface comparable): " + students);

        Collections.sort(students, new ReverseComparator());
        System.out.println("\nReverse order (interface comparable): " + students);
    }
}