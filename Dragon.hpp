#ifndef DRAGON_HPP
#define DRAGON_HPP

#define DRAGON_HEAD 0
#define DRAGON_BODY 1
#define DRAGON_WINGS 2
#define DRAGON_TAIL 3

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
    0, 1, 2, // tanduk
    1, 3, 4, // kepala
    2, 4, 5, // mulai leher (deket kepala)
    4, 5, 6, // sisa lehernya (ke deket badan)
    1, 4, 7, // rahang bawah naga
    4, 6, 8, // pelengkap leher naga
    2, 5, 9, //bagian belakang leher naga, 1
    5, 10, 11, // bagian belakang leher naga, 2
    11, 12, 13 // bagian belakang leher naga, 3

}; // which indices of the points do you want to make as triangles?


float dragonBodyVertices[] = {
    580.0f, 493.0f, 0.0f, // 0 "dada" naga
    503.0f, 488.0f, 0.0f, // 1 akhir leher naga (belakang leher)
    535.0f, 574.0f, 0.0f, // 2 deket kaki depan, bagian depan
    521.0f, 651.0f, 0.0f, // 3 kaki depan
    486.0f, 566.0f, 0.0f, // 4 paha naga, bagian tengah
    503.0f, 488.0f, 0.0f, // 5 akhir leher naga (deket badan)
    426.0f, 571.0f, 0.0f, // 6 ketek? naga
    473.0f, 645.0f, 0.0f, // 7 kaki depan, bagian belakang
    324.0f, 483.0f, 0.0f, // 8 punggung belakang
    353.0f, 563.0f, 0.0f, // 9 paha belakang, bagian tengah
    452.0f, 535.0f, 0.0f, // 10 bukan titik, di antara 1 dan 6
    315.0f, 577.0f, 0.0f, // 11 pantat naga
    297.0f, 601.0f, 0.0f, // 12 pangkal ekor naga (deket 11)
    260.0f, 523.0f, 0.0f, // 13 pangkal ekor naga, bagian atas
    345.0f, 626.0f, 0.0f, // 14 kaki naga belakang, bagian yang ketutupan huruf T kebalik (tengah)
    404.0f, 573.0f, 0.0f, // 15 paha belakang naga, bagian depan
    319.0f, 617.0f, 0.0f, // 16 kaki naga belakang, belakang
    371.0f, 633.0f, 0.0f, // 17 kaki naga belakang, depan
    296
};

unsigned int dragonBodyIndices[] = {
    0, 1, 2, // dada
    2, 3, 4, // paha depan
    4, 5, 6, // paha belakang bagian atas
    3, 6, 7, // paha belakang pt1
    // 3, 4, 6, // paha belakang pt2
    6, 8, 9, // punggung belakang, tapi bagian bawah dan belakang
    1, 8, 10, // punggung belakang
    8, 9, 11, // tempat paha belakang
    8, 12, 13, // pangkal ekor naga
    11, 14, 16, // paha belakang 1
    14, 15, 17, // paha belakang 2
    8, 11, 12, // penutup pangkal ekor naga
    1, 6, 10, // penutup bagian tengah badan


};

float dragonWingsVertices[] = {
    389.0f, 506.0f, 0.0f, // 0 punggung, kiri
    470.0f, 510.0f, 0.0f, // 1 punggung, tengah, agak ke kanan
    491.0f, 485.0f, 0.0f, // 2 punggung, kanan, agak atas
    259.0f, 384.0f, 0.0f, // 3 antara segment 1 dan 2
    514.0f, 260.0f, 0.0f, // 4 CONNECTOR POINT for all wing lines
    360.0f, 385.0f, 0.0f, // 5 point 2 segment sayap 1 <kanan>
    391.0f, 391.0f, 0.0f, // 6 outer segment sayap 1 <kanan dari 5>
    148.0f, 310.0f, 0.0f, // 7 antara segment 2 dan 3
    98.0f , 383.0f, 0.0f, // 8 ujung segment 2
    31.0f , 265.0f, 0.0f, // 9 ujung segment 3
    213.0f, 170.0f, 0.0f, // 10 antara segment 3 dan 4
    160.0f, 40.0f , 0.0f, // 11 ujung segment 4

};

unsigned int dragonWingsIndices[] = {
    // Segment 1 bagian bawah
    0, 1, 3, 
    1, 3, 5,
    // end

    3, 4, 5, // Segment 1 atas
    4, 5, 6, // Segment atas, outer segment

    // Outer segment, bawah
    1, 2, 6,
    1, 5, 6,
    // end

    // Segment 2
    3, 4, 8,
    4, 7, 8,
    // end

    // Segment 3
    4, 7, 9,
    4, 9, 10,
    // end

    4, 10, 11 // Segment 4

};

float dragonTailVertices[] = {

};

unsigned int dragonTailIndices[] = {
    
};


#endif