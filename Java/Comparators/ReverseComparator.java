package Java.Comparators;

import java.util.Comparator;

public class ReverseComparator implements Comparator<Estudante> {
    @Override
    public int compare(Estudante one, Estudante two) {
        return two.getAge() - one.getAge();
    }

}
