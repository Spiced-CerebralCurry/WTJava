package LabAssignmentFive;

public class Code extends Thread{
    public void run()
    {
        try
        {
            System.out.println("Hi current::"+Thread.currentThread());
            System.out.println("Hi current Id::"+Thread.currentThread().getId());
            System.out.println("Hi current Name::"+Thread.currentThread().getName());
            System.out.println("Hi current Priority::"+Thread.currentThread().getPriority());
            System.out.println("Hi current ThreadGroup::"+Thread.currentThread().getThreadGroup());
        }
        catch (Exception exception)
        {
            System.out.println("Error="+exception);
        }
        finally {
            System.out.println("Total:"+ Thread.activeCount());
        }
    }
}
