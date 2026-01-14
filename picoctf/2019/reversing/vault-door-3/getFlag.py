#java code 
"""
class Answere{
    public void Main(){
        System.out.print(getFlag());
    }
public String getFlag() {
    String Password = "jU5t_a_sna_3lpm18gb41_u_4_mfr340";
    if (password.length() != 32) {
        return false;
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
    return s; //.equals("jU5t_a_sna_3lpm18gb41_u_4_mfr340");
}
}
"""
input = "jU5t_a_sna_3lpm18gb41_u_4_mfr340"
flag  = ""
for i in range(8):
    flag+=input[i]
for i in range(8,16,1):
    flag+= chr(ord(input[23])-i)
for i in range(16,32,2):
    flag+= input[46-i]
val = flag[:16]
for i in range(16,32,2):
    val += input[i]
    if i>31:
        val += flag[i+1]
print()
print(val,end="}\n")