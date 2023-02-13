package Java.List;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class MyList {
    public static void main(String[] args) {
        List<String> names = new ArrayList<>();
        System.out.println(names.isEmpty());

        names.add("Joao");
        names.add("Marcos");
        names.add("Maria");
        names.add("Rosa");
        names.add("Ana");
        names.add("Pedro");
        names.add("Carla");
        System.out.println(names);

        Collections.sort(names);
        System.out.println(names);

        System.out.println(names.get(names.size() - 1));

        names.set(0, "Lara");
        System.out.println(names);

        names.remove(0);
        System.out.println(names);
        names.remove("Marcos");
        System.out.println(names);

        System.out.println(names.contains("Ana"));
        System.out.println(names.indexOf("Carla"));

        for (String listNames: names) {
            System.out.println(listNames);
        }
        Iterator<String> iteratorList = names.iterator();
        while (iteratorList.hasNext()) {
            System.out.println("- "+ iteratorList.next());
        }
    }
}