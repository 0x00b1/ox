# Ox

## Tagged union

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

    union A {
        a: (8-bit Integer × 8-bit Integer × 8-bit Integer),
        b: {
            a: 8-bit Integer,
            b: 8-bit Integer,
            c: 8-bit Integer
        }
    };

    a ← A.a(1, 2, 3);

    b ← A.b {
        a: 1,
        b: 2,
        c: 3
    };

In the aforementioned example, `A.a` is a tuple-like tagged union variant and `A.b` is a record-like tagged union variant. Tagged union elements have a discriminant, an integer that’s used to determine its variant. If there’s no variant attached to any of the elements of a tagged union, then the discriminant can be directly chosen and accessed.

    union A {
        a ← 1,
        b,
        c
    };

    a: 8-bit Integer ← A.a as 8-bit Integer; # a = 1
    b: 8-bit Integer ← A.b as 8-bit Integer; # b = 2
    c: 8-bit Integer ← A.c as 8-bit Integer; # c = 3

    union A {
        a: 16-bit Integer,
        b: 32-bit Integer,
        c: 64-bit Integer
    };

    union Option ⟨T⟩ {
        None,
        Some: (T)
    };
