package tk.faunsce.java;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.text.*;
import java.util.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import javafx.util.Pair;

public class bizz_sim {
    public static void main(String[] args) throws IOException {
        // Non data data
        DecimalFormat format = new DecimalFormat("$###,###,###.00");
        DateFormat dateFormat = new SimpleDateFormat("MM_dd_yyyy");
        List<String> lines;
        Path file = Paths.get("Receipt_[" + dateFormat.format(new Date()) + "].txt");
        Scanner input = new Scanner(System.in);
        System.out.println(file);
        // Data
        RetailItem clothes = new RetailItem("Black T-Shirt", 100, 50.0);
        double item_value = 50.0;

        // Get quantity
        System.out.println("Please input how many " + clothes.getDescription() + "'s (" + format.format(clothes.getPrice()) + "/each) you are purchasing");
        int quantity = input.nextInt();

        // Create Data
        CashRegister checkout = new CashRegister(new Pair<RetailItem, Integer>(clothes, quantity));
        lines = Arrays.asList(
                "SALES RECEIPT",
                "Unit Price: $50.00",
                "Quantity: " + Integer.toString(quantity),
                "Subtotal: " + format.format(checkout.getSubTotal()),
                "Sales Tax: " + format.format(checkout.getTax()),
                "Total: " + format.format(checkout.getTotal())
        );

        // Print to file
        /* for (String line : lines) { // Debugging Code
            System.out.println(line);
        }
        */
        Files.write(file, lines, StandardCharsets.UTF_8);
    }
}
