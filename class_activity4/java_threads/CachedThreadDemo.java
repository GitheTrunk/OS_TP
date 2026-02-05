import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CachedThreadDemo {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();

        for (int i = 1; i <= 10; i++) {
            int taskId = i;
            executor.execute(() -> {
                System.out.println(
                    "Task " + taskId +
                    " running on " + Thread.currentThread().getName()
                );
                try { Thread.sleep(2000); } catch (Exception e) {}
            });
        }

        executor.shutdown();
    }
}

