/* 

Ders6

Fonksiyonlar (Function, Subroutine)

double func (int x, int y)
{

}

fonksiyonun parametre değişkeni
formal parameter 

C dili geçmişe doğru uyumlu bir dildir. Bu standartlar tarafından temel bir ilkedir.

explicit 

implicit int
(örtülü - gizli - kapalı)

C89 standartlarında dilin kuralları gereği eğer belli bir alanı boş bırakırsak int yazmış kabul ediliyor.

implicit int kuralı günümüzde geçerli değildir. C99 standartlarıyla dilden kaldırılmıştır.

Derleyiciler implicit int durumlarında hata vermezler, uyarı verebilirler.

C89 standartlarında fonksiyonun geri dönüş değerini boş bırakmak varsayılan olarak int türü kabul edilir. (implicit int)

Geri dönüş değeri olmayan bir fonksiyon tanımlamak istediğimiz void anahtar sözcüğünü kullanıyoruz.

Fonksiyonun parametre değişkenleri otomatik ömürlü değişkenlerdir.

void func(void)
{

}

Otomatik ömürlü değişkenler ile Statik ömürlü değişkenlerin farkı

++Bu program çalıştırıldığında a değişkenin değeri hep 10 olacak.

void func(void)
{
    int a = 10;     //otomatik ömürlü yerel değişken
    
    printf("a = %d\n", a);

    a += 5;
}

int main ()
{
    func();
    func();
    func();
    func();

}
-----------------------------------------------------------------------

++Bu program çalıştırıldığında a değişkeni hayata bir kere gelecek.
++Bu fonksiyon kaç kere çağrılırsa çağrılsın bu bildirim bir daha hayata gelmeyecek.


void func(void)
{
    static int a = 10;     //statik ömürlü yerel değişken
    
    printf("a = %d\n", a);

    a += 5;
}

int main ()
{
    func();
    func();
    func();
    func();

}

C ve C++ dillerinde bir fonksiyonun içerisinde bir fonksiyon tanımlanması yoktur. Sentaks hatasıdır.
Fonksiyon içinde fonksiyon tanımlanamaz.

Bütün fonksiyonlar global alanda ayrı ayrı tanımlanırlar.

Fonksiyonların geri dönüş değeri üretmesi ve return deyimi

RETURN STATEMENT

Statements

expression statement
x + 5;
compound statement
{

}
null statement
;
control statement
if
while
for
do while

switch
go to

continue
break
return

-----------------------------------------------------------------------

RETURN STATEMENT

Yalın Return Deyimi (İfadesiz Return Deyimi)
return;

Yanında ifade olan return deyimi (İfadeli Return Deyimi)
return expr;

Yalın return deyimi void fonksiyonlarda kullanılır.
Geri dönüş değeri üretmeyen fonksiyonlar kullanılır.

Return deyiminin yürütülmesiyle bir fonksiyonun kodunun çalışması sona erer.

void func(void)
{
    statement1;
    statement2;
    if(x > 10)
        return;
    statement3;
}

Return ifadesinin değeri hesaplanır ve hesaplanan değer fonksiyonun geri dönüş değeri olarak fonksiyonu çağıran koda iletilir.

return x + y;
return a * a * a;
return 8;

C ve C++ dillerinde bir fonksiyon yalnızca tek bir değer döndürebilir.


//one-liner
Bir fonksiyonun kodu tek bir satırsa, bu fonksiyona one-liner fonksiyon deniliyor.

int sum (int x, int y)
{
    return x + y;
}

int max2 (int x, int y)
{
    if (x > y)
        return x;
    
    return y;
}  

int abs (int x)
{
    if (x < 0)
        return -x;
    return x;
}

int max3 (int x, int y, int z)
{
    int max = x;
    
    if (y > max)
        max = y;
    if (z > y)
        max = c;
    
    return max;
}

Geri dönüş değeri olan bir fonksiyonun tanımında return deyimi olmaması tanımsız davranıştır. 
Fonksiyonun geri dönüş değeri çöp değerindedir. Garbage value - indetermined value.
Derleyicinin yaptığı lojik kontrollere takılır.

Örnek Fonksiyon:

int func (int x)
{
    if (x > 210)
        return x;
    //?? return deyimi yok.
}

1) Bir fonksiyonun geri dönüş değeri o fonksiyonun varlık nedeni olabilir. Yani fonksiyon zaten o değeri hesaplamak için vardır. 
Doğal olarak bu fonksiyonun geri dönüş değeri hesaplanan değerdir.

Örnek: Kürenin hacmini hesaplayan fonksiyon
Örnek: 3 sayıdan en büyüğünü hesaplayan fonksiyon

2) Bir soruya evet/hayır doğru/yanlış geçerli/geçersiz yanıtını veren fonksiyonlar. Fonksiyonun varlık nedeni bir soruya cevap vermek.
test functions
query functions
predicate

Bu tarz test fonksiyonlarının geri dönüş tipi int'dır.

int is_prime
int is_valid_card
int isupper

C'de geleneksel olarak boolean yerine int türü kullanılır.

boolean false => int x = 0;
boolean true => non zero.

3) Geri dönüş değeri başarı değeri olan fonksiyonlar vardır. 
Bu fonksiyonlar işlerini yaptıktan sonra geri dönüş değeri olarak başarı bilgisini iletebilir.

connect_database
open_file
transfer_data

int remove(const char *p)

C'de geleneksel olarak main fonksiyonun geri dönüş değeri int yapılır.

//main fonksiyonun geri dönüş değeri programın geri dönüş değeri
0 => başarı (program işini yaptı, program başardı)

int main(void)
{
    return 0;
}

int main(void)
{
    return 1; //program burada sonlandırılmış fakat işini yapamamış.
}

int main()
{
    FILE* f;

    f = fopen("database.dat", "rb");
    if (f == NULL) {
        fprintf(stderr, "veri tabanı açılamıyor\n");
        return 1;
    }

    return 0;
}

exited with code 0.
exited with code 1.

------------------------------------------------------------------------------------------------

C99 standartlarıyla main fonksiyonunda return deyimi yoksa, derleyici bunu kendisi ekliyor.

int main(void)
{
    //C99 Standartlarıyla derleyici buraya "return 0; ekliyor, eğer yoksa.
}

return 1; ne demek? -> Bu tamamen fonksiyona bağlı bir bilgidir. Programın akışına, contexte, fonksiyona bağlıdır.

------------------------------------------------------------------------------------------------

4) Bazı fonksiyonların geri dönüş değeri tamamlayıcı bir bilgi.

Örnek olarak: printf fonksiyonu. int printf(const char *, ...);
Bu fonksiyonun geri dönüş değer bilgisi ekrana yazılan karakter sayısıdır.

5) Bazı fonksiyonların ise geri dönüş değeri yoktur. (void fonksiyonlar)
Fonksiyon bir değer hesaplıyor olabilir ama geri dönüş mekanizması ile göndermiyordur.
Veya fonksiyon geriye hiçbir değer göndermiyordur. (ekran temizleyen fonksiyon)

void clear_screen(void);
void sleep(double millisecond);

 */
