package Java.Map;

import java.util.HashMap;
import java.util.Map;

public class MyHashMap {
    public static void main(String[] args) {
        Map<String, Integer> copas = new HashMap<>();
        copas.put("Brasil", 5);
        copas.put("Argentina", 3);
        copas.put("Franca", 2);
        copas.put("Alemanha", 4);
        copas.put("Espanha", 1);
        copas.put("Inglaterra", 1);
        System.out.println(copas);

        copas.put("Brasil", 6);

        System.out.println(copas.get("Argentina"));
        System.out.println(copas.containsKey("Franca"));
        copas.remove("Franca");
        System.out.println(copas.containsValue(5));

        for (Map.Entry<String, Integer> entry: copas.entrySet()) {
            System.out.println(entry.getKey() + " - " + entry.getValue());
        }
        System.out.println("-----");
        for (String key: copas.keySet()) {
            System.out.println(key + " - " + copas.get(key));
        }
    }
}
