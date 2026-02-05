import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class SingleThreadDemo {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();

        for (int i = 1; i <= 5; i++) {
            int taskId = i;
            executor.execute(() -> {
                System.out.println(
                    "Task " + taskId +
                    " running on " + Thread.currentThread().getName()
                );
            });
        }

        executor.shutdown();
    }
}
