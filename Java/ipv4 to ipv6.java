public class IPv4ToIPv6String {
    public static void main(String[] args) {
        String ipv4 = "127.0.0.1";  // Replace with your IPv4 address
        
        // Split the IPv4 address into its individual parts
        String[] octets = ipv4.split("\\.");
        
        // Check if the input is a valid IPv4 address
        if (octets.length != 4) {
            System.out.println("invalid output");
            return;
        }
        
        // Check if the IPv4 address is a loopback address (starts with 127)
        if (octets[0].equals("127")) {
            System.out.println("::1");
            return;
        }
        
        // Validate each octet
        try {
            for (String octet : octets) {
                int value = Integer.parseInt(octet);
                if (value < 0 || value > 255) {
                    System.out.println("invalid output");
                    return;
                }
            }
        } catch (NumberFormatException e) {
            System.out.println("invalid output");
            return;
        }
        
        // Convert each part to hexadecimal and build the IPv6-mapped IPv4 address
        String ipv6 = String.format("::ffff:%02x%02x:%02x%02x", 
                                    Integer.parseInt(octets[0]), 
                                    Integer.parseInt(octets[1]), 
                                    Integer.parseInt(octets[2]), 
                                    Integer.parseInt(octets[3]));
        
        // Print the IPv6 equivalent
        System.out.println("IPv6 equivalent: " + ipv6);
    }
}
