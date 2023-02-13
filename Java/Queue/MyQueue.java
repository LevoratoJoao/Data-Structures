package Java.Queue;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class MyQueue {
    public static void main(String[] args) {
        Queue<String> queue = new LinkedList<>();
        queue.add("Joao");
        queue.add("Marcos");
        queue.add("Maria");
        queue.add("Rosa");
        queue.add("Ana");
        queue.add("Pedro");
        queue.add("Carla");
        System.out.println(queue);

        System.out.println(queue.poll() + " Was the first in queue and was removed\n"); //get the first in the queue and remove it
        System.out.println(queue);

        System.out.println(queue.peek() + " is the first in queue and was not removed from the queue\n"); //get the first in the queue but dont remove it
        System.out.println(queue);

        System.out.println(queue.element() + " is the first in queue and was not removed from the queue\n"); //get the first in the queue but dont remove it and if the queue is null it return an error
        System.out.println(queue);

        Iterator<String> iteratorQueue = queue.iterator();
        while (iteratorQueue.hasNext()) {
            System.out.println("- " + iteratorQueue.next());
        }

        queue.clear();
    }
}
