# Ox

    /*
     *  Tagged union
     */

    union A {};

    union A {
        a,
        b,
        c
    };

    union A {
        a: (),
        b: (),
        c: ()
    };

    union A: 8-bit Integer {
        a ← 1,
        b
    };

    union A {
        a: 16-bit Integer,
        b: 32-bit Integer,
        c: 64-bit Integer
    };

    a ← A.a(1);
    
    b ← A.b(2);
    
    c ← A.c(3);

    union A {
        a: 8-bit Integer,
        b: (8-bit Integer × 8-bit Integer × 8-bit Integer)
    };

    a ← A.a(1);
    
    b ← A.b(1, 2, 3);

    union A {
        a: 8-bit Integer,
        b: {
            a: 8-bit Integer,
            b: 8-bit Integer,
            c: 8-bit Integer
        }
    };

    a ← A.a(1);

    b ← A.b {
        a: 1,
        b: 2,
        c: 3
    };

    union Option ⟨T⟩ {
        None,
        Some: (T)
    };
