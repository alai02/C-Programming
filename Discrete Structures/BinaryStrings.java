import java.util.Scanner;

public class A2 {

    public static void main(String[] args) {
        
        
        Scanner scanner = new Scanner(System.in);
        
        String questA = String.format("%0"+ 3+"d", Integer.valueOf(Integer.toBinaryString(1)));
        String questB = String.format("%0"+ 4+"d", Integer.valueOf(Integer.toBinaryString(0)));
        
        System.out.print("Enter a number: ");
        
        long n = 11;
        int questACount = 0;
        int questBCount = 0;
        String displayProperly="%0"+n+"d";
        String display = "%0"+ 3+"d";
        
        for (long i = 0; i < Math.pow(2,n); i++) {    
        
            String compare = String.format(displayProperly, Long.valueOf(Long.toBinaryString(i)));
            
            System.out.printf(displayProperly,Long.valueOf(Long.toBinaryString(i)));
            System.out.println();
            
            if(compare.contains(questA)){
                questACount++;
            }
            
            if(compare.contains(questB)){
                questBCount++;
            }
       }
        
        System.out.println("Count: " + questACount);
        System.out.println("Second Count: " + questBCount);
        
        
    }
    
}
