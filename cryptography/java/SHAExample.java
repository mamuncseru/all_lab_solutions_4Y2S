import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;
import java.nio.charset.StandardCharsets;

public class SHAExample {

    private static String bytesToHex(byte[] hash) {
        StringBuilder hexString = new StringBuilder(2 * hash.length);
        for (int i = 0; i < hash.length; i++) {
            String hex = Integer.toHexString(0xff & hash[i]);
            if (hex.length() == 1) {
                hexString.append('O');
            }
            hexString.append(hex);
        }

        return hexString.toString();

    }
    
    public static void main(String[] args) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] encodedhash = digest.digest(
                "Hello World".getBytes(StandardCharsets.UTF_8));
            System.out.println(encodedhash);
            System.out.println(bytesToHex(encodedhash));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
