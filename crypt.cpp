#include<iostream>
#include<string>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
//ceaser cipher code
class encrypt
{
 int key;
 string line;
 string newline;
 int len;
 public:
 void input(){
 cout<<"Enter the sentence : ";
 getline(cin,line);
 cout<<"Enter the key :(1-4) ";
 cin>>key;
 if(key>4){
 cout<<"Invalid key";
 }
 len=line.length();
 ofstream outfile("Orignal.txt");
 if (outfile.is_open()) {
 outfile << line << endl;
 outfile.close();
 } else {
 cout << "Unable to open file!" << endl;
 }
 }
 void enc()
 {
 for(int i=0; i<line.length(); i++)
 {
 int val = int(line[i]);
 if((val > 122) || (val<33)){
 newline+=char(val);
 }
 else{
 newline += (char(val + key));
 }
}
 cout<<"encrypted data is:"<<endl;
 cout<<newline<<endl;
 ofstream outencrypted("cipher.txt");
 if (outencrypted.is_open()) {
 outencrypted << newline << endl;
 outencrypted.close();
 } else {
 cout << "Unable to open file 'cipher.txt' for writing!" << endl;
 }
}
 void dec()
 {
 string ln;
 ifstream infile("cipher.txt");
 if (infile.is_open()) {
 string line;
 while (getline(infile, line)) {
 ln=line;
 }
 infile.close();
 }
else {
 cout << "Unable to open file!" << endl;
}
 cout<<"Decrypted data"<<endl;
 string fin;
 for(int i=0; i<len; i++){
 int val2= int(ln[i]);
 if((val2 > 126) || (val2<33)){
 fin+=char(val2);
 }
 else{
 fin += (char(val2-key));
 }
 }
 cout<<fin<<endl;
 }
};
//morse+ceaser cipher
void decrypt()
{ string m;
 ifstream inpfile ("ENCRYPTED.txt");
 if(inpfile.is_open())
 {
 string d;
 while(getline(inpfile,d))
 {
 cout<<"Follwing will be decrypted"<<endl;
 cout<<d<<endl;
 m=d;
 }
 inpfile.close();
 }
else {
 cout << "Unable to open file!" << endl;}
 int len;
 len=m.length();
 string dec;
 int i = 0;
 while (i < len) {
 string w;
 while (m[i] != ' ' && i < len) {
 w = w + m[i];
 i++;
 }
 if (w == "._") {
 dec += "a";
 }
 else if (w == "_...") {
 dec += "b";
 }
 else if (w == "..") {
 dec += "c";
 }
 else if (w == "_..") {
 dec += "d";
 }
 else if (w == ".") {
 dec += "e";
 }
 else if (w == ".._.") {
 dec += "f";
 }
 else if (w == ".") {
 dec += "g";
 }
 else if (w == "....") {
 dec += "h";
 }
 else if (w == "..") {
 dec += "i";
 }
 else if (w == "._") {
 dec += "j";
 }
 else if (w == ".") {
 dec += "k";
 }
 else if (w == "._..") {
 dec += "l";
 }
 else if (w == "") {
 dec += "m";
 }
 else if (w == "_.") {
 dec += "n";
 }
 else if (w == "_") {
 dec += "o";
 }
 else if (w == "..") {
dec += "p";
 }
 else if (w == "._") {
 dec += "q";
 }
 else if (w == "._.") {
 dec += "r";
 }
 else if (w == "...") {
 dec += "s";
 }
 else if (w == "_") {
 dec += "t";
 }
 else if (w == ".._") {
 dec += "u";
 }
 else if (w == "..._") {
 dec += "v";
 }
 else if (w == ".") {
 dec += "w";
 }
 else if (w == "..") {
 dec += "x";
 }
 else if (w == "._") {
 dec += "y";
 }
 else if (w == "..") {
 dec += "z";
 }
 else if (w == ".") {
 dec += "1";
 }
 else if (w == ".._") {
 dec += "2";
 }
 else if (w == "...") {
 dec += "3";
 }
 else if (w == "...._") {
 dec += "4";
 }
 else if (w == ".....") {
 dec += "5";
 }
 else if (w == "_....") {
 dec += "6";
 }
 else if (w == "...") {
 dec += "7";
 }
 else if (w == "_..") {
 dec += "8";
 }
 else if (w == ".") {
 dec += "9";
 }
 else if (w == "_") {
dec += "0";
 }
 else if (w == "....") {
 dec += "?";
 }
 else if (w == "..") {
 dec += "!";
 }
 else if (w == "..._") {
 dec += ".";
 }
 else if (w == "..") {
 dec += ",";
 }
 else if (w == ".._.") {
 dec += ";";
 }
 else if (w == "_...") {
 dec += ":";
 }
 else if (w == "...") {
 dec += "+";
 }
 else if (w == "....") {
 dec += "-";
 }
 else if (w == "...") {
 dec += "/";
 }
 else if (w == "...") {
 dec += "=";
 }
 else if (w==" "){
 dec+=" ";
 }
 else {
 dec += "@";
 }
 while (m[i] == ' ' && i < len) {
 if (m[i + 1] == ' ' && m[i + 2] != ' ') {
 dec += " ";
 }
 i++;
 }
 }
 ofstream odec("decrypt1.txt");
if (odec.is_open()) {
 odec << dec << endl;
 odec.close();
}
else {
 cout << "Unable to open file!" << endl;
}
}
void encrypted(){
 string s;
 string in;
 int l = 0;
 ifstream ifile("cipher.txt");
if (ifile.is_open()) {
 string samp;
 while (getline(ifile, samp)) {
 //cout << samp << endl;
 if (samp.length() > l) {
 l = samp.length();
 in = samp;
 }
 }
 ifile.close();
 }
 else {
 cout << "Unable to open file 'Orignal.txt' for reading!" << endl;
 }
for(int i=0;i<l;i++){
 if(in.at(i)=='a'||in.at(i)=='A'){
 s+="._ ";
 }
 else if(in.at(i)=='b'||in.at(i)=='B'){
 s+="_... ";
 }
 else if(in.at(i)=='c'||in.at(i)=='C'){
 s+=".. ";
 }
 else if(in.at(i)=='d'||in.at(i)=='D'){
 s+="_.. ";
 }
 else if(in.at(i)=='e'||in.at(i)=='E'){
 s+=". ";
 }
 else if(in.at(i)=='f'||in.at(i)=='F'){
 s+=".._. ";
 }
 else if(in.at(i)=='g'||in.at(i)=='G'){
 s+=". ";
 }
 else if(in.at(i)=='h'||in.at(i)=='H'){
 s+=".... ";
 }
 else if(in.at(i)=='i'||in.at(i)=='I'){
 s+=".. ";
 }
 else if(in.at(i)=='j'||in.at(i)=='J'){
 s+="._ ";
 }
 else if(in.at(i)=='k'||in.at(i)=='K'){
 s+=". ";
 }
 else if(in.at(i)=='l'||in.at(i)=='L'){
 s+="._.. ";
 }
 else if(in.at(i)=='m'||in.at(i)=='M'){
 s+="__ ";
 }
 else if(in.at(i)=='n'||in.at(i)=='N'){
 s+="_. ";
 }
 else if(in.at(i)=='o'||in.at(i)=='O'){
 s+="_ ";
 }
else if(in.at(i)=='p'||in.at(i)=='P'){
 s+=".. ";
 }
 else if(in.at(i)=='q'||in.at(i)=='Q'){
 s+="._ ";
 }
 else if(in.at(i)=='r'||in.at(i)=='R'){
 s+="._. ";
 }
 else if(in.at(i)=='s'||in.at(i)=='S'){
 s+="... ";
 }
 else if(in.at(i)=='t'||in.at(i)=='T'){
 s+="_ ";
 }
 else if(in.at(i)=='u'||in.at(i)=='U'){
 s+=".._ ";
 }
 else if(in.at(i)=='v'||in.at(i)=='V'){
 s+="..._ ";
 }
 else if(in.at(i)=='w'||in.at(i)=='W'){
 s+=".__ ";
 }
 else if(in.at(i)=='x'||in.at(i)=='X'){
 s+=".. ";
 }
 else if(in.at(i)=='y'||in.at(i)=='Y'){
 s+="._ ";
 }
 else if(in.at(i)=='z'||in.at(i)=='Z'){
 s+=".. ";
 }
 else if(in.at(i)=='1'){
 s+=".__ ";
 }
 else if(in.at(i)=='2'){
 s+=".._ ";
 }
 else if(in.at(i)=='3'){
 s+="...__ ";
 }
 else if(in.at(i)=='4'){
 s+="...._ ";
 }
 else if(in.at(i)=='5'){
 s+="..... ";
 }
 else if(in.at(i)=='6'){
 s+="_.... ";
 }
 else if(in.at(i)=='7'){
 s+="... ";
 }
 else if(in.at(i)=='8'){
 s+="_.. ";
 }
 else if(in.at(i)=='9'){
 s+=". ";
 }
else if(in.at(i)=='0'){
 s+="___ ";
 }
 else if(in.at(i)=='?'){
 s+=".... ";
 }
 else if(in.at(i)=='!'){
 s+="..__ ";
 }
 else if(in.at(i)=='.'){
 s+="..._ ";
 }
 else if(in.at(i)==','){
 s+="..__ ";
 }
 else if(in.at(i)==';'){
 s+=".._. ";
 }
 else if(in.at(i)==':'){
 s+="_... ";
 }
 else if(in.at(i)=='+'){
 s+="... ";
 }
 else if(in.at(i)=='-'){
 s+=".... ";
 }
 else if(in.at(i)=='/'){
 s+="... ";
 }
 else if(in.at(i)=='='){
 s+="... ";
 }
 else if(in.at(i)==' '){
 s+=" ";
 }
 else{
 s+=".. ";
 }
}
ofstream outencrypted("ENCRYPTED.txt");
if (outencrypted.is_open()) {
 outencrypted << s << endl;
 outencrypted.close();
}
else {
 cout << "Unable to open file!" << endl;
}
}
class encrypt2
{
 int key;
 string line;
 string newline;
 int len;
public:
 void input(){
 cout<<"Enter the sentence : ";
 getline(cin,line);
 cout<<"Enter the key :(1-4) ";
 cin>>key;
 if(key>4){
 cout<<"Invalid key";
 }
 len=line.length();
 ofstream outfile("Orignal.txt");
 if (outfile.is_open()) {
 outfile << line << endl;
 outfile.close();
 } else {
 cout << "Unable to open file!" << endl;
 }
 }
 void enc()
 {
 for(int i=0; i<line.length(); i++)
 {
 int val = int(line[i]);
 if((val > 122) || (val<33)){
 newline+=char(val);
 }
 else{
 newline += (char(val + key));
 }
 }
 ofstream outencrypted("cipher.txt");
 if (outencrypted.is_open()) {
 outencrypted << newline << endl;
 outencrypted.close();
 } else {
 cout << "Unable to open file 'cipher.txt' for writing!" << endl;
 }
}
 void dec()
 {
 string ln;
 ifstream infile("decrypt1.txt");
 if (infile.is_open()) {
 string line;
 while (getline(infile, line)) {
 ln=line;
 }
 infile.close();
 }
else {
 cout << "Unable to open file!" << endl;
}
 cout<<"Decrypted data"<<endl<<endl;
string fin;
 for(int i=0; i<len; i++){
 int val2= int(ln[i]);
 if((val2 > 126) || (val2<33)){
 fin+=char(val2);
 }
 else{
 fin += (char(val2-key));
 }
 }
 cout<<fin<<endl;
 }
};
//rsa
int hcf(int a, int b) {
 if (b == 0) {
 return a;
 }
 return hcf(b, a % b);
}
// Function to calculate a^b mod m
int modpow(int a, int b, int m) {
 int result = 1;
 while (b > 0) {
 if (b & 1) {
 result = (result * a) % m;
 }
 a = (a * a) % m;
 b >= 1;
 }
 return result;
}
// Function to calculate Euler's Totient Function
int phi(int n) {
 int result = n;
 for (int i = 2; i <= sqrt(n); i++) {
 if (n % i == 0) {
 while (n % i == 0) {
 n /= i;
 }
 result -= result / i;
 }
 }
 if (n > 1) {
 result -= result / n;
 }
 return result;
}
// Function to generate a random primitive root modulo n
int proot(int n) {
 int phiN = phi(n);
 int e = 2;
 while (hcf(e, phiN) != 1) {
 e++;
 }
 return e;
}
int main(){
 encrypt e;
 encrypt2 e2;
 cout<<"Welcome to ArShaDe! The one stop destination to empower organizations and individuals with robust encryption technologies that uphold the highest standards of security and privacy. Our mission is to deliverinnovative encryption solutions that enable secure data storage, transmission, and communication across diverse platforms and environments."<<endl;
 cout<<"we offer three levels of encryption:"<<endl;
 cout<<"1.Basic : Caesar cipher, a simple encryption technique that operates by shifting the letters of thealphabet by a fixed number of positions. The encryption process involves replacing each letter in the plaintext withanother letter positioned a fixed distance away in the alphabet."<<endl;
 cout<<"Price : Rs.10,000"<<endl;
 cout<<"2.Intermediate : Caesar cipher combined with morse code which provides an added level of security toyour data where the data is first encrypted using caesar cipher and then using morse code"<<endl;
 cout<<"Price : Rs.30,000"<<endl;
 cout<<"3.RSA, a widely-used encryption algorithm that relies on the mathematical complexity of factoring largenumbers. It involves generating a public key for encryption and a private key for decryption. RSA is secure due tothe difficulty of factoring large numbers into their prime components without the private key."<<endl;
 cout<<"Price : Rs.1,00,000"<<endl;
 cout<<"Make an informed choice to keep your data safe!"<<endl;
 int ch2,dp;
 while(1){
 cout<<"Choose the level of encryption:"<<endl;
 cout<<"1. basic level"<<endl;
 cout<<"2. Intermediate"<<endl;
 cout<<"3. Advanced"<<endl;
 cout<<"4. Decryption"<<endl;
 cin>>ch2;
 cin.ignore();
 if(ch2==1){
 e.input();
 e.enc();
 }
 else if(ch2==2){
 e2.input();
 cout<<"Encryption started"<<endl;
 for(int i=0;i<3;i++){
 cout<<"."<<endl;}
 e2.enc();
 encrypted();
 cout<<"Encryption over"<<endl;
 }
 else if(ch2==3){
 string sen;
 ofstream outputfile("RSA.txt");
 if (outputfile.is_open()) {
 cout<<"input data"<<endl;
 getline(cin,sen);
 outputfile<< sen << endl;
 outputfile.close();
 } else {
 cout << "Unable to open file 'RSA.txt' for writing!" << endl;
 }
 ifstream inputFile("RSA.txt");
 if (!inputFile) {
 cerr << "Error: Unable to open input file!" << endl;
return 1;
 }
 string message;
 getline(inputFile, message);
 inputFile.close();
 // RSA Parameters
 int p = 61;
 int q = 53;
 int n = p * q;
 int phiN = (p - 1) * (q - 1);
 int e = proot(phiN); // public key
 int d = 0;//STORES private key
 while ((d * e) % phiN != 1) {
 d++;
 }
 ofstream outputFile("output.txt");
 if (!outputFile) {
 cerr << "Error: Unable to open output file!" << endl;
 return 1;
 }
 outputFile << "Original message: " << message << endl;
 outputFile << "Encrypted message: ";
 for (int i = 0; i < message.length(); i++) {
 int numerical_message = (int)message[i]; // Convert character to ASCII value
 int encrypted_character = modpow(numerical_message, e, n);
 outputFile << encrypted_character << " ";
 }
 outputFile.close();
 cout << "Encryption complete. Encrypted message written to output.txt" << endl;
 ifstream encryptedFile("output.txt");
 if (!encryptedFile) {
 cerr << "Error: Unable to open encrypted file!" << endl;
 return 1;
 }
 string line;
 while (getline(encryptedFile, line)) {
 cout << line << endl;
 }
 encryptedFile.close();
 ifstream encryptedFile2("encrypted.txt");
 if (!encryptedFile2) {
 cerr << "Error: Unable to open encrypted file!" << endl;
 return 1;
 }
 getline(encryptedFile, line); // Skip the first line
 cout << "Decrypted message: ";
 while (getline(encryptedFile2, line)) {
 stringstream ss(line);
 int encrypted_character;
 while (ss >> encrypted_character) {
 ofstream outputsfile("decrypted.txt");
 int decrypted_character = modpow(encrypted_character, d, n);
 outputsfile<< (char)decrypted_character;
 cout << (char)decrypted_character;
}
 }
 encryptedFile2.close();
 cout << endl;
 cout << "Decryption complete. Decrypted message written to decrypted.txt" << endl;
 ofstream outputsfile("Decrypted.txt");
 if (!outputsfile) {
 cerr << "Error: Unable to open decrypted file!" << endl;
 return 1;
 }
 cout<<"decrypted message :"<<message<<endl;
 encryptedFile.close();
 }
 else if(ch2==4){
 cout<<"Choose which level to decrypt"<<endl;
 cout<<"1. basic level"<<endl;
 cout<<"2. Intermediate"<<endl;
 cout<<"3. Advanced"<<endl;
 cin>>dp;
 if(dp==1){
 e.dec();
 }
 else if(dp==2){
 cout<<"decryption started"<<endl;
 for(int k=0;k<3;k++){
 cout<<"."<<endl;}
 decrypt();
 e2.dec();
 }
 else{
 cout<<"Enter valid choice"<<endl;
 }
 }
 }
}
