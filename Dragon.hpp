#ifndef DRAGON_HPP
#define DRAGON_HPP

#define DRAGON_HEAD 0
#define DRAGON_BODY 1
#define DRAGON_WINGS 2
#define DRAGON_TAIL 3

/* Vertice Dict */
// 0 1 2 = tanduk
// 1 3 4 = kepala
// 2 4 5 = mulai leher (deket kepala)
// 4 5 6 = sisa lehernya (ke deket badan)
// 1 4 7 = rahang bawah naga
// 4 6 8 = pelengkap leher naga
// 2 5 9, 5 10 11, 11 12 13 = bagian belakang leher naga, 1 2 3

float dragonHeadVertices[] = { 
    408.0f, 296.0f, 0.0f, // 0 ujung tanduk
    538.0f, 332.0f, 0.0f, // 1 tanduk - kanan
    502.0f, 343.0f, 0.0f, // 2 tanduk - bawah
    624.0f, 373.0f, 0.0f, // 3 hidung naga
    539.0f, 385.0f, 0.0f, // 4 "bawahnya dagu" (deket leher) naga
    493.0f, 368.0f, 0.0f, // 5 belakang kepala naga
    503.0f, 488.0f, 0.0f, // 6 akhir leher naga (deket badan)
    587.0f, 393.0f, 0.0f, // 7 "bibir" naga
    580.0f, 493.0f, 0.0f, // 8 "dada" naga

    // Gambar "bagian belakang" leher naga
    465.0f, 375.0f, 0.0f, // 9 belakang 1 (atas, tapi ujungnya)
    457.0f, 420.0f, 0.0f, // 10 belakang 2 (tengah, tapi ujungnya)
    495.0f, 409.0f, 0.0f, // 11 belakang 2 & 3 (persimpangan)
    472.0f, 446.0f, 0.0f, // 12 belakang 3 (bawah, tapi ujungnya)
    496.0f, 441.0f, 0.0f, // 13 belakang 3 (bawah, bagian yang melekat ke leher)

}; // Vertices


unsigned int dragonHeadIndices[] = {
    0, 1, 2, 
    1, 3, 4, 
    2, 4, 5, 
    4, 5, 6, 
    1, 4, 7, 
    4, 6, 8,
    2, 5, 9,
    5, 10, 11,
    11, 12, 13

}; // which indices of the points do you want to make as triangles?


float dragonBodyVertices[] = {
    580.0f, 493.0f, 0.0f, // 0 "dada" naga
    503.0f, 488.0f, 0.0f, // 1 akhir leher naga (belakang leher)
    535.0f, 574.0f, 0.0f, // 2 deket kaki depan, bagian depan

    
};

unsigned int dragonBodyIndices[] = {
    0, 1, 2
};

float dragonWingsVertices = {

};

unsigned int dragonWingsIndices = {

};

float dragonTailVertices = {

};

unsigned int dragonTailIndices[] = {
    
};


#endif