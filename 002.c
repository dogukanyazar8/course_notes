/* 

Ders2

Dosya
İkincil saklama ortamlarında ikilik sayı sisteminde tutulan verilerdir.

100001010000100010001010001010100 (File Format - Dosya Formatı)
En çok kullanılan metin formatı ASCII Text File'dır.

BABA
66 65 66 65 (4 byte'lık büyüklüğünde bir metin)

Bit (Binary Digit)

Translator: Programın amacı bir dilde yazılmış bir programı başka bir dile çevirmekse, çevirici (translator) olarak adlandırılır.
Compiler: Bu çevirme işleminde daha yüksek bir seviyeli dilden, düşük seviyeye çeviren program compiler (derleyici) olarak adlandırılır.

Derleyici için kaynak dosya bir birimdir. Translation Unit. Çeviri birimi.
-----------------------------------------------------------------------
Source File (Kaynak dosyası - guitar_tuner.c veya arpeggio.cpp)

Preprocessor        (Önişlemci)
Translation Unit    (Çeviri Birimi)
Compiler            (Derleyici)
Assembly Code       (Makine Kodu)
Assembler           (Makine Kodu Çeviricisi)
Object Code         (Hedef Kod)
Linker              (Bağlayıcı)
Executable Code     (Çalıştırılabilir Kod)
-----------------------------------------------------------------------

Preprocessing Time (Önişlemci Zamanı)
Compile Time (Derleme Zamanı)
Link Time (Bağlama Zamanı)
Run Time (Çalışma Zamanı)

Pre-processor Directives (Önişlemci Komutları)

C ve C++ dillerinde, derleyicinin giriş modülüdür ve ayrı bir programdır.
Ön işlemci kendi komutlarını yürütür, bu komutlara önişlemci komutları denir.
# karakteri ile başlayan satırlar önişlemci programın komutlarıdır.
#define

Bulgu İletisi

Diagnastic (Message) (Dilin kuralları ihlal edildiğinde derleyicinin ürettiği hata mesajlarıdır. Derleyici bazen kodu derleyip, warning mesajı verebilir.)
    Error Message (%99)
    Warning Message

Syntax Error (Sentaks Hatası)
ill-formed code well-formed code
illegal code    legal code (perfectly legal)
invalid code    valid code

Geçersiz Kod
Yanlış Kod
Kötü Kod

Derleyici sentaks kontrolÜ, lojik kontrol ve optimizasyon yapar.

Warning (Lojik Uyarı Mesajları)
Derleyici bazı durumlarda, dilin kuralları çiğnememiş olsa bilse, bir kodu yanlışlıkla yazdığımızı düşünerek bizi uyarıyor. %95 Haklıdır.

Compiler Switches
Derleyicinin uyarı ayarlarını değiştirip lojik kontrolleri sıkılaştırıp, gevşetebiliriz. (Warning Level)

Optimizing Compilers
Derleyiciler kodu derlerken düzenleyerek, en iyi hâle getirirler. Optimize ederler.

Döngüler, programın en çok zaman kaybettiği yerlerden birisidir. Derleyici yazdığımız döngüleri düzenleyip, optimize ederler.
Loop Reversal
Loop Unrolling
Death-code Elimination

İkilik Sayı Sistemi

Integers            (Tam Sayılar)
    Unsigned        (İşaretsiz - Negatif tam sayılar mevcut değil.)
    Signed          (İşaretli - Hem pozitif hem negatif tam sayılar mevcut.)
Floating Numbers    (Gerçek Sayılar)

Bit (Binary Digit)
Byte = 8 Bit

Most Significant Bit    (En Yüksek Anlamlı Bit)
Least Significant Bit   (En Düşük Anlamlı Bit)

1 Byte  255
2 Byte  65.635
4 Byte  4.294.967.295
8 Byte  18.446.744.073.709.551.615

One's Complement (Bire Tümleme)
Sayıdaki bütün bitler ters çevrilir. (1'ler 0. 0'lar 1.)

Two's Complement (İkiye Tümleme)
Sayı ilk önce bire tümlenir. Ardından 1 eklenir.
KISAYOL: 0. bitten başlayarak, 1 görene kadar aynen yazılır, kalan bitlerin tersi yazılır.

0101 1100
1111 1111
0010 1000
0001 0000

Negatif bir tam sayının değerini almak için o sayının ikiye tümleyini alınır.

Atomlar

token (atom)
Derleyici açısından kaynak kodun en küçük birimi.

Derleme işleminin başında derleyici kaynak kodu token'larına ayırır. (tokenizing - atomlarına ayrıma)
Bu süreçte derleyici elde ettiği her bir atomu kategorilerine ayrır.

Atom kategorileri şunlardır

keywords        (anahtar sözcükler)
isimler         (identifiers)
sabitler        (constant / literal)
operators       (operatörler - işleçler)
yazı sabitleri  (string literals)
ayraçlar        (delimeters)

-----------------------------------------------------------------------
KEYWORDS (Anahtar Sözcükler)

Dil tarafından rezerve edilen başka bir amaçla kullanılması yasaklanan sözcükler.
C89 standartlarına göre C dilinde 32 anahtar sözcük vardır.

auto break case char const continue default do
double else enum extern float for goto if
int long register return short signed sizeof static
struct switch typedef union unsigned void volatile while

C99 standartları ile 5 anahtar sözcük daha dile eklenmiştir.

restrict inline _Bool _Complex _Imaginary

C11 standartları ile 7 anahtar sözcük daha dile eklenmiştir.

_Alignas _Alignof _Atomic _Generic _Noreturn _ Static_assert _Thread_local
-----------------------------------------------------------------------
IDENTIFIERS (İsimler)

İsimler kaynak koddaki, kaynak dosyadaki varlıklara verilen adlardır.

Nelerin isimleri var;

variables       (Değişkenlerin)
functions       (Fonksiyonların)
constants       (Sabitlerin)
tags/labels     (Etiketlerin)
types           (Türlerin)

1) Anahtar sözcükler isim olarak kullanılamaz.
2) İsimler 63 karakterlik aşağıda tanımlanan karakter kümesi dışında karakter içeremez.

A..Z    26  Latin-Roman karakter setindeki büyük harf karakterler
a..z    26  Latin-Roman karakter setindeki küçük harf karakterler
0..9    19  Rakam karakterleri (Arabic Numerals)
_           Alt tire karakteri (underscore)

İsimler rakam karakterleri ile başlayamaz.
C isimlerin kullanımı açısından case-sensitive (büyük/küçük harf duyarlı) bir dildir.

case-sensitive      (büyük/küçük harf duyarlı)
case-insensitive    (büyük/küçük harf duyarsız)

Aşağıdaki isimlerin her biri farklı isimlerdir.

Sum sum suM SUM

*/
