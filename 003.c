/* 

Ders3

-----------------------------------------------------------------------
OPERATORS (Operatörler)

Dilin işlem yaptıran atomlarına operatör denir.
C dilinin 45 operatörü vardır.
Bazı operatörler tek karakterlik atomlardır. Örnek: + - ~ !
Bazı operatörler iki karakterlik atomlardır. Örnek: >= || ++ ==
Bazı operatörler üç karakterlik atomlardır.  Örnek: >>= <<=
sizeof bir anahtar sözcük olmasına karşın C dilinin bir operatörü olarak kullanılmaktadır.
-----------------------------------------------------------------------
CONSTANT (Sabitler)

Doğrudan sayısal bütünlük ifade eden atomlar.

x = 24;     // x bir identifier. 24 ise sabit.

Tam sayı sabitlerini 3 ayrı şekilde ifade etme olanağımız var.

x = 123;    10'luk sayı sistemi ifadesi (123)
x = 0x123;  16'lık sayı sistemi ifadesi (291)
x = 0123;    8'lik sayı sistemi ifadesi (83)

Çift tırnak içerisinde yazılan atomlar ayrı bir kategoridir. Yazı sabitleri (string literals)

"Arpeggio" 

sum += val;     
// sum (identifier)
// += (operator)
// val (identifier)
// ; ()

"sum += val;"
//tek bir atomdur.

C, C++, C#, Java gibi programlama dilleri atomik dillerdir. Yani kaynak kodun en küçük birimi bir atomdur.
Atomlar arasındaki boşluk karakterlerinin (white-space) kodun üzerinde bir etkisi yoktur. 
Compiler için bir etkisi yoktur.

Code Convention (Konvensiyon)
Code Layout     (Yerleşim)
-----------------------------------------------------------------------
EXPRESSION (İfade)

C ve C++ dillerinde bir ifade, 
İsimlerin, Operatörlerin, Sabitlerin oluşturduğu bir birim.

if(expression)

x               //ifade
24              //ifade
x = 12          //ifade
y = x + 10 > 5  //ifade

Bir ifadenin bütününü değil de, bir bileşenini kastettiğimizde ona sub-expression denir.

İfadenin Değer Kategorisi (Value Category)

Bir ifade, ya bir sol taraf değeri ifadesidir, ya da bir sağ taraf değeri ifadesidir. İkisi birden olamaz.

L Value Expression (Sol taraf değeri ifadesi)
R Value Expression (Sağ taraf değeri ifadesi)

L Value Expression: 
Okuma veya yazma amacıyla kullanabilecek, erişilebilir bir bellek alanından, yerden bahsediyoruz.
Object (Nesne) (Programın çalışma zamanındaki bellekteki bir yer)
Örnek: x = 10; x; a[8];

R Value Expression:
Bellekte bir yere karşılık gelmiyor. 
Aritmetik operatörlerle oluşturulan hiçbir ifade sağ taraf değeri olamaz.
Örnek: x + 8

Eğer ifadeyi adres operatörünün operandı yaptığımızda derleyici;
sentaks hatası verirse sağ taraf değeridir, 
sentaks hatası vermezse sol taraf değeridir.

int a[10];

&[5];

EXPRESSION -> Data Type (Veri Türü)
Her ifadenin bir veri türü olmak zorundadır. Dil tarafından belirlenmiş türlerden biri olmak zorundadır.
Bir ifadenin değeri ve türü vardır.

int x = 10;
x + 2;

value of an expression (ifadenin değeri)

EXPRESSION -> Constant Expression (Sabit İfadesi)
Derleyici, derleme zamanında ifadenin değerini tam olarak hesaplayabiliyor.
Yani ifadenin değeri programın çalışma zamanına ilişkin değil, derleme zamanında ilişkindir.

x + y           //sabit ifadesi değildir.
10 + 20 - 5     //sabit ifadesidir. (25)

int a[buradaki_sabit_ifadesi_olması_gerekir];
int a[10];

Object (Nesne) (Variable)

C dilinde nesnelerin veri türleri vardır.

staticly typed language (c,c++,java,c#)
derleyici derleme zamanında verinin türünü koda bakarak anlıyor, yorumluyor.
dynamicly typed language ()
derleyici derleme zamanında verinin türünü programın çalışma zamanında anlıyor, yorumluyor.

nesnenin türü
data type of an object

a) söz konusu nesne için bellekte kaç byte yer ayrılacak,
storage of an object (STORAGE).
bunu belirleyen nesnenin türüdür.

b) bu byte'lardaki 1'ler ve sıfırların nasıl yorumlanacağını, veri türünü.

c) değer kategorileri (value category)

d) sabit ifadesi olup olmadıkları (constant - non constant expression)

DATA TYPES (Veri Türleri)

Basic Types (fundamental types - default tpyes - built-in types - primitive)
User Defined Types (Kodla oluşturulan veri türü diyebiliriz(programcı tarafından oluşturulan))

C dilinin cümleleri.

Declaration     (Bildirim)
Bildirimler isimlerin ne anlama geldiğini, ne olduğunu anlatan C cümleleridir.
int x;
void func(int);

Statement       (Deyim)  (namelookup)
Derleyicinin kod üretmesini sağlayacak C cümleleridir. İşlem yaptırmaya yönelik.
a = b + c;

Expression statement (İfade Deyimi)
    x++;
İfadenin sonuna noktalı virgül koyularak ifade deyimi elde edilebilir.

Null Statement
;

Compound Statements (Bileşik Deyimler) Blokların oluşturduğu deyimler.
{
    //Opening Brace - Left Brace
    //Closing Brace - Right Brace
}

Control Statements
Dil tarafından belirlenmiş özel sentaksa sahiplerdir.
En az bir anahtar sözcükleriyle kullanırlar.
Varlık nedenleri ise programın çalışma zamanında programın akış yönünü belirlemek, değiştirmek, yönlendirmek.

if

while
do while
for
switch

goto

break
continue
return

Declaration  (Bildirim)

Definition   (Tanımlama)
Derleyicinin, programın çalışma zamanına yönelik bellekte bir yer ayırması gerekiyor. 

Her tanımlama bir bildirimdir ama her bildirim bir tanımlama olmak zorunda değildir.
-----------------------------------------------------------------------
C dilinin sentaksında kullanmayan karakterler.

´ (Backtick)
@ (At Sign)
$ (Dollar Sign)

printable characters

punctuation characters

()  Paranthesis (Opening/Left Paranthesis - Closing/Right Paranthesis)
[]  Square Bracket
{}  Curly Brace
< > Angular Bracket (Açısal Parantez)
&   Ampersand
*   Asterisk
,   Comma
-   Hypen (dash)
.   Period (full stop)
:   colon
;   semicolon
_   underscore
^   caret
|   pipe
~   tilde (tilda)

control characters
-----------------------------------------------------------------------

 method
 subroutine
 procedure
 function

 alt program
 ana programın bir parçasını oluşturan, bağımsız bir işi gerçekleştirmek için yazılan kod birimi.

 Global Namespace (Global İsim Alanı)
 Bu isim alanında sadece bildirim yazılabilir, deyim yazılamıyor.

 Local Namespace  (Lokal İsim Alanı)
 Bu isim alanında bildirim de yazılabilir, deyim de yazılabilir.
 -----------------------------------------------------------------------
function (fonksiyon-işlev)

to define   a function (fonksiyonu tanımlamak, fonksiyonun kodunu yazmak, implement etmek)
function definition (fonksiyon tanımı)

to call     a function (fonksiyonu çağırmak)
function call (fonksiyon çağrısı)

to declare  a fuctiton (fonksiyonu bildirmek)
function declaration (fonksiyon bildirimi)
-----------------------------------------------------------------------

#include <stdio.h>

int main(void) 
{
    printf("hello world!");
}

main block of a function
-----------------------------------------------------------------------

data types (veri türleri)

declaration & definition
    scope (kapsam)
    name lookup (isim arama)
    storage duration (ömür)

-----------------------------------------------------------------------
Tanımsız Davranış       (Undefined Behavior) (UB)
Derleyicinin nasıl bir kod üreteceği konusunda bir garanti yok. Derleme zamanında ya da programın çalışma zamanında her şey olabilir.
Bu duruma bizim beklentimiz de dahil. (Program çalışma zamanında beklediğiniz gibi doğru çalışıyordur fakat bu programın doğru olduğu anlamına gelmiyor.)
Neden UB var? Bunun sebebi derleyici optimizasyonu.

a) derleyici sentaks hatası verebilir
b) derleyici uyarı mesajı verebilir
c) derleyici sessiz kalabilir

Örnek olarak işaretli tam sayı türlerinde taşma (overflow) tanımsız davranıştır.

Belirlenmemiş Davranış  (Unspecified Behavior)
Derleyici standartların belirlediği iki ya da daha fazla seçeneğe göre kod üretebilir. Derleyici nasıl bir kod üreteceğini belgelemek zorunda değildir.

Derleyiciye Bağlı Durum      (Implementation-Defined)
Derleyici standartların belirlediği iki ya da daha fazla seçeneğe göre kod üretebilir. Derleyici nasıl bir kod üreteceğini belgelemek zorundadır.
Belirlenmemiş Davranışın bir alt kümesi. 

 */
