package Java.Map;

import java.util.TreeMap;
import java.util.Map;

public class MyTreeMap {
    public static void main(String[] args) {
        TreeMap<String, String> capitals = new TreeMap<>();

        capitals.put("RS", "Porto Alegre");
        capitals.put("SC", "Florianopolis");
        capitals.put("SP", "São Paulo");
        capitals.put("PR", "Curitiba");
        capitals.put("RJ", "Rio de Janeiro");
        capitals.put("PA", "Belem");
        capitals.put("MG", "Belo Horizonte");
        System.out.println(capitals);

        System.out.println("First: " + capitals.firstKey());
        System.out.println("Last: " + capitals.lastKey());
        System.out.println("Lower: " + capitals.lowerKey("PA"));
        System.out.println("Higher: " + capitals.higherKey("PR"));

        System.out.println("First Entry: " +capitals.firstEntry().getKey() + " - " + capitals.firstEntry().getValue());
        System.out.println("Last Entry: " +capitals.lastEntry().getKey() + " - " + capitals.lastEntry().getValue());
        System.out.println("Lower Entry: " +capitals.lowerEntry("SP").getKey() + " - " + capitals.lowerEntry("SP").getValue());
        System.out.println("Higher Entry: " + capitals.higherEntry("RJ").getKey() + " - " + capitals.higherEntry("RJ").getValue());

        Map.Entry<String, String> firstEntry = capitals.pollFirstEntry();
        System.out.println(firstEntry);

        Map.Entry<String, String> lastEntry = capitals.pollFirstEntry();
        System.out.println(lastEntry);

    }
}
