class Answere{
    public static void main(String[] argv){
        System.out.print(getFlag());
    }
public static String getFlag() {
    String password = "jU5t_a_sna_3lpm18gb41_u_4_mfr340";
    if (password.length() != 32) {
        return "";
    }
    char[] buffer = new char[32];
    int i;
    for (i=0; i<8; i++) {
        buffer[i] = password.charAt(i);
    }
    for (; i<16; i++) {
        buffer[i] = password.charAt(23-i);
    }
    for (; i<32; i+=2) {
        buffer[i] = password.charAt(46-i);
    }
    for (i=31; i>=17; i-=2) {
        buffer[i] = password.charAt(i);
    }
    String s = new String(buffer);
    return "picoCTF{"+s+"}"; //.equals("jU5t_a_sna_3lpm18gb41_u_4_mfr340");
}
}