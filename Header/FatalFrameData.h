#pragma once
#include "json.hpp"
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sys/types.h>

using namespace nlohmann;

namespace FatalData
{

    typedef short s_short;
    typedef char s_char;
    typedef long s_long;

    enum GAME_MODE
    {
        GAME_MODE_INIT = 0,
        GAME_MODE_MCCHECK = 1,
        GAME_MODE_OUTGAME = 2,
        GAME_MODE_INGAME = 3
    };

    enum GAME_MODE_CHANGE
    {
        GMC_OUT_MENU_IN = 0,
        GMC_IN_GAMEOVER_OUT = 1,
        GMC_IN_GAMECLEAR_OUT = 2,
        GMC_IN_GAMERETIRE_OUT = 3
    };

    enum INGAME_MODE
    {
        INGAME_MODE_FIRST_LOAD = 0,
        INGAME_MODE_INIT = 1,
        INGAME_MODE_WAIT = 2,
        INGAME_MODE_NEW_GAME = 3,
        INGAME_MODE_LOAD_START = 4,
        INGAME_MODE_MSN_TITLE = 5,
        INGAME_MODE_NOMAL = 6,
        INGAME_MODE_EVENT = 7,
        INGAME_MODE_SPECIAL_EVENT = 8,
        INGAME_MODE_AREA_MOVE = 9,
        INGAME_MODE_MENU = 10,
        INGAME_MODE_PAUSE = 11,
        INGAME_MODE_SPD_MAP = 12,
        INGAME_MODE_SPD_OPT = 13,
        INGAME_MODE_GET_ITEM = 14,
        INGAME_MODE_WANDER_SOUL = 15,
        INGAME_MODE_SAVE_POINT = 16,
        INGAME_MODE_PHOTO_AFTER = 17,
        INGAME_MODE_GHOST_DEAD = 18,
        INGAME_MODE_SGST_DISP = 19,
        INGAME_MODE_GAME_OVER = 20,
        INGAME_MODE_GAME_OVER_ALBUM = 21,
        INGAME_MODE_INTER_MSN = 22,
        INGAME_MODE_ENDING = 23,
        INGAME_MODE_WAIT_MSN0 = 24
    };

    enum
    {
        OG_TITLE_MODE = 0,
        OG_LOADGAME_MODE = 1,
        OG_OPTION_MODE = 2,
        OG_ALBUM_MODE = 3,
        OG_MOVIE_MODE = 4,
        OG_DEMOPLAY_MODE = 5,
        OG_NAME_ENTRY_MODE = 6,
        OG_MAPDATA_EDIT_MODE = 7,
        OG_SOUND_TEST_MODE = 8,
        OG_SCENE_TEST_MODE = 9,
        OG_MOTION_TEST_MODE = 10,
        OG_2D_TEST_MODE = 11
    };

    enum OUTGAME_MODE
    {
        OUTGAME_MODE_INIT = 0,
        OUTGAME_MODE_WAIT = 1,
        OUTGAME_MODE_LOGO = 2,
        OUTGAME_MODE_TITLE_TOP = 3,
        OUTGAME_MODE_TITLE = 4,
        OUTGAME_MODE_ALBUM = 5,
        OUTGAME_MODE_BATTLE = 6,
        OUTGAME_MODE_OPTION = 7,
        OUTGAME_MODE_MODESEL = 8,
        OUTGAME_MODE_MAP_DATA_EDIT = 9,
        OUTGAME_MODE_SOUND_TEST = 10,
        OUTGAME_MODE_SCENE_TEST = 11,
        OUTGAME_MODE_MOTION_TEST = 12,
        OUTGAME_MODE_ROOM_SIZE_CHECK = 13,
        OUTGAME_MODE_LAYOUT_TEST = 14,
        OUTGAME_MODE_DBG_MAX = 9,
        OUTGAME_MODE_DBG_STORY_MODE = 5
    };

    enum TITLE_MODE
    {
        TITLE_INIT = 0,
        TITLE_WAIT = 1,
        TITLE_TITLE = 2,
        TITLE_TITLE_WAIT = 3,
        TITLE_TITLE_WAIT2 = 4,
        TITLE_TITLE_SEL = 5,
        TITLE_LOAD_PRE = 6,
        TITLE_MEMCA_LOAD_WAIT = 7,
        TITLE_MEMCA_LOAD = 8,
        TITLE_MODE_SEL = 9,
        TITLE_DIFF_SEL = 10,
        TITLE_INIT_FROM_IN = 11,
        TITLE_WAIT_FROM_IN = 12,
        TITLE_MODE_SELECT = 13,
        TITLE_ALBM_LOAD_PRE = 14,
        TITLE_ALBM_LOAD1 = 15,
        TITLE_ALBM_LOAD2 = 16,
        TITLE_ALBM_MAIN_PRE = 17,
        TITLE_ALBM_MAIN = 18,
        TITLE_ALBM_SAVE_PRE = 19,
        TITLE_ALBM_SAVE = 20,
        TITLE_ALBM_LOAD_MODE_PRE = 21,
        TITLE_ALBM_LOAD_MODE = 22,
        TITLE_TITLE_SEL_INIT = 23,
        TITLE_TITLE_SEL_BGMREQ = 24,
        TITLE_ALBM_LOAD0 = 25,
        TITLE_INIT_FROM_IN_BGMREQ = 26,
        TITLE_MODE_SEL_BGMREQ = 27,
        TITLE_MOVIE_STEP1 = 28,
        TITLE_MOVIE_STEP2 = 29,
        TITLE_MOVIE_STEP3 = 30
    };

    struct sceVu0FVECTOR
    {
        float x;
        float y;
        float z;
        float w;

        void Print()
        {
            printf("X: %f\n", x);
            printf("Y: %f\n", y);
            printf("Z: %f\n", z);
            printf("W: %f\n", w);
        }
    };

    static inline void to_json(json &j, const sceVu0FVECTOR &v)
    {
        j = json{{"X", v.x}, {"Y", v.y}, {"Z", v.z}, {"W", v.w}};
    }

    typedef struct
    {
        u_int attr1;
        u_short dst_gthr;
        u_char way_gthr;
        u_char atk_ptn;
        u_char wspd;
        u_char rspd;
        u_short hp;
        u_short atk_rng;
        u_short hit_rng;
        u_short chance_rng;
        short int hit_adjx;
        u_short atk_p;
        u_short atk_h;
        u_char atk;
        u_char atk_tm;
        u_short mdl_no;
        u_short anm_no;
        u_int se_no;
        u_int adpcm_no;
        int dead_adpcm;
        u_short point_base;
        u_char hint_pic;
        u_char aura_alp;
        u_char area[1];
        u_short dir;
        u_short px;
        short int py;
        u_short pz;
    } ENE_DAT;

    static inline void to_json(json &j, const ENE_DAT &dat)
    {
        j = json{{"attr1", dat.attr1},
                 {"dst_gthr", dat.dst_gthr},
                 {"way_gthr", dat.way_gthr},
                 {"atk_ptn", dat.atk_ptn},
                 {"wspd", dat.wspd},
                 {"rspd", dat.rspd},
                 {"hp", dat.hp},
                 {"atk_rng", dat.atk_rng},
                 {"hit_rng", dat.hit_rng},
                 {"chance_rng", dat.chance_rng},
                 {"hit_adjx", dat.hit_adjx},
                 {"atk_p", dat.atk_p},
                 {"atk_h", dat.atk_h},
                 {"atk", dat.atk},
                 {"atk_tm", dat.atk_tm},
                 {"mdl_no", dat.mdl_no},
                 {"anm_no", dat.anm_no},
                 {"se_no", dat.se_no},
                 {"adpcm_no", dat.adpcm_no},
                 {"dead_adpcm", dat.dead_adpcm},
                 {"point_base", dat.point_base},
                 {"hint_pic", dat.hint_pic},
                 {"aura_alp", dat.aura_alp},
                 {"area", dat.area},
                 {"dir", dat.dir},
                 {"px", dat.px},
                 {"py", dat.py},
                 {"pz", dat.pz}};
    }

    union P_INT
    {
        u_char *pu8;
        u_short *pu16;
        u_int *pu32;
        u_long *pu64;
        s_char *ps8;
        s_short *ps16;
        int *ps32;
        s_long *ps64;
        long int wrk;

        void Print()
        {
            printf("pu8 %u\n", (uint8_t)*pu8);
            printf("pu16 %u\n", *pu16);
            printf("pu32 %u\n", *pu32);
            printf("pu64 %lu\n", *pu64);
            printf("ps8 %u\n", (int8_t)*ps8);
            printf("ps16 %d\n", *ps16);
            printf("ps32 %d\n", *ps32);
            printf("pu8 %ld\n", *ps64);
            printf("pu8 %ld\n", wrk);
        }
    };

    struct MOVE_BOX
    {
        u_char job_no;
        u_char pos_no;
        u_char wait_time;
        u_char idx;
        u_short loop;
        u_short reserve;
        int se;
        sceVu0FVECTOR pos;
        sceVu0FVECTOR tpos;
        sceVu0FVECTOR spd;
        sceVu0FVECTOR rot;
        sceVu0FVECTOR rspd;
        sceVu0FVECTOR trot;
        sceVu0FVECTOR pos_mid;
        P_INT comm_add;
        long int comm_add_top;

        void Print()
        {
            printf("job_no %u\n", (uint8_t)job_no);
            printf("pos_no %u\n", (uint8_t)pos_no);
            printf("wait_time %u\n", (uint8_t)wait_time);
            printf("idx %u\n", (uint8_t)idx);
            printf("loop %u\n", loop);
            printf("reserve %u\n", reserve);
            printf("se %u\n", se);
            printf("\n");
            printf("Pos: \n");
            pos.Print();
            printf("tPos: \n");
            tpos.Print();
            printf("Spd: \n");
            spd.Print();
            printf("Rot: \n");
            rot.Print();
            printf("Rspd: \n");
            rspd.Print();
            printf("Trot: \n");
            trot.Print();
            printf("Pos_Mid: \n");
            pos_mid.Print();
            printf("\n");
            printf("comm_add_top %ld\n", comm_add_top);
        }
    };

    static void to_json(json &j, const MOVE_BOX &b)
    {
        j = json{{"job_no", b.job_no},
                 {"pos_no", b.pos_no},
                 {"wait_time", b.wait_time},
                 {"idx", b.idx},
                 {"loop", b.loop},
                 {"reserve", b.reserve},
                 {"se", b.se},
                 {"pos", b.pos},
                 {"tpos", b.tpos},
                 {"spd", b.spd},
                 {"rot", b.rot},
                 {"rspd", b.rspd},
                 {"trot", b.trot},
                 {"pos_mid", b.pos_mid},
                 {"com_add_top", b.comm_add_top}};
    }

    struct MPOS
    {
        sceVu0FVECTOR p0;
        sceVu0FVECTOR p1;
        sceVu0FVECTOR p2;
        sceVu0FVECTOR p3;
        sceVu0FVECTOR p4;
        sceVu0FVECTOR p5;
        sceVu0FVECTOR p6;
        sceVu0FVECTOR p7;
        sceVu0FVECTOR p8;
        sceVu0FVECTOR p9;
        void Print()
        {
            printf("P0: \n");
            p0.Print();
            printf("P1: \n");
            p1.Print();
            printf("P2: \n");
            p2.Print();
            printf("P3: \n");
            p3.Print();
            printf("P4: \n");
            p4.Print();
            printf("P5: \n");
            p5.Print();
            printf("P6: \n");
            p6.Print();
            printf("P7: \n");
            p7.Print();
            printf("P8: \n");
            p8.Print();
            printf("P9: \n");
            p9.Print();
        }
    };

    static void to_json(json &j, const MPOS &pos)
    {
        j = json{{"p0", pos.p0}, {"p1", pos.p1}, {"p2", pos.p2}, {"p3", pos.p3}, {"p4", pos.p4}, {"p5", pos.p5}, {"p6", pos.p6}, {"p7", pos.p7}, {"p8", pos.p8}, {"p9", pos.p9}};
    }
    typedef struct
    {
        sceVu0FVECTOR direction;
        sceVu0FVECTOR diffuse;
    } PARARELL_WRK;

    static void to_json(json &j, const PARARELL_WRK &pw)
    {
        j = json{{"direction", pw.direction}, {"diffuse", pw.diffuse}};
    }

    typedef struct
    {
        sceVu0FVECTOR pos;
        sceVu0FVECTOR diffuse;
        float power;
        float pad[1];
    } POINT_WRK;

    static void to_json(json &j, const POINT_WRK &pw)
    {
        j = json{{"pos", pw.pos}, {"diffuse", pw.diffuse}, {"power", pw.power}};
    }

    typedef struct
    {
        sceVu0FVECTOR pos;
        sceVu0FVECTOR direction;
        sceVu0FVECTOR diffuse;
        float intens;
        float power;
        float pad[1];
    } SPOT_WRK;

    static void to_json(json &j, const SPOT_WRK &sw)
    {
        j = json{{"pos", sw.pos},
                 {"direction", sw.direction},
                 {"diffuse", sw.diffuse},
                 {"intens", sw.intens},
                 {"power", sw.power}};
    }

    struct LIGHT_PACK
    {
        int parallel_num;
        int point_num;
        int spot_num;
        int pad;
        sceVu0FVECTOR ambient;
        PARARELL_WRK parallel[1];
        POINT_WRK point[1];
        SPOT_WRK spot[1];

        void Print()
        {
            printf("Parrallel_Num: %d\n", parallel_num);
            printf("Point_Num: %d\n", point_num);
            printf("spot_Num: %d\n", spot_num);
            printf("Pad: %d\n", pad);
            printf("Ambient \n");
            ambient.Print();
        }
    };

    struct INGAME_WRK
    {
        u_char game;
        u_char mode;
        u_char init_flg;
        u_char stts;
        u_char msn_no;
        u_char difficult;
        u_char clear_count;
        u_char rg_pht_cnt;
        u_short ghost_cnt;
        u_int pht_cnt;
        u_int high_score;
        u_int total_point;
        u_int padding;

        void Print()
        {
            printf("INGAME_WRK: \n");
            printf("Game: %03u\n", (uint8_t)game);
            printf("Mode: %03u\n", (uint8_t)mode);
            printf("Init_Flg: %03u\n", (uint8_t)init_flg);
            printf("Stts: %03u\n", (uint8_t)stts);
            printf("Msn_No: %03u\n", (uint8_t)msn_no);
            printf("Difficult: %03u\n", (uint8_t)difficult);
            printf("Clear_Count: %03u\n", (uint8_t)clear_count);
            printf("Rg_Pht_Cnt: %03u\n", (uint8_t)rg_pht_cnt);
            printf("Ghost_Cnt: %u\n", ghost_cnt);
            printf("Pht_Cnt: %u\n", pht_cnt);
            printf("High_Score: %u\n", high_score);
            printf("Total_Point: %u\n", total_point);
        }
    };

    static void to_json(json &j, const LIGHT_PACK &l)
    {
        j = json{{"parallel_num", l.parallel_num},
                 {"point_num", l.point_num},
                 {"spot_num", l.spot_num},
                 {"ambient", l.ambient},
                 {"parallel", l.parallel},
                 {"point", l.point},
                 {"spot", l.spot}};
    }

    typedef struct
    {
        u_char dat_no;
        u_char soul_no;
        u_short dir;
        u_short px;
        short int py;
        u_short pz;
        u_short adpcm_tm;
        int adpcm_no;
        u_short rng;
        u_short mdl_no;
        u_short anm_no;
        u_short point_base;
        u_int se_no;
        int se_foot;
    } AENE_INFO_DAT;

    struct sceVu0FMATRIX
    {
        sceVu0FVECTOR matrix[4];
    };

    typedef struct
    {
        sceVu0FVECTOR p;
        sceVu0FVECTOR i;
        float roll;
        float fov;
        float nearz;
        float farz;
        float ax;
        float ay;
        float cx;
        float cy;
        float zmin;
        float zmax;
        float pad[1];
        sceVu0FMATRIX vs;
        sceVu0FMATRIX vc;
        sceVu0FMATRIX vcv;
        sceVu0FMATRIX wv;
        sceVu0FMATRIX ws;
        sceVu0FMATRIX wc;
        sceVu0FMATRIX wcv;
        sceVu0FVECTOR zd;
        sceVu0FVECTOR yd;
    } SgCAMERA;

    static void to_json(json &j, const AENE_INFO_DAT &i)
    {
        j = json{{"dat_no", i.dat_no},
                 {"soul_no", i.soul_no},
                 {"dir", i.dir},
                 {"px", i.px},
                 {"py", i.py},
                 {"pz", i.pz},
                 {"adpcm_tm", i.adpcm_tm},
                 {"adpcm_no", i.adpcm_no},
                 {"rng", i.rng},
                 {"mdl_no", i.mdl_no},
                 {"anm_no", i.anm_no},
                 {"point_base", i.point_base},
                 {"se_no", i.se_no},
                 {"se_foot", i.se_foot}};
    }
    struct ENE_WRK
    { // 0x430
        // 2 sets battle
        u_int sta;

        // Something battle related?
        u_int sta2;

        u_short hp;
        u_short dmg;
        u_short dmg_old;
        u_short atk_tm;

        // 0 jibakurei, 1 Fuyu, 2, Jidou
        u_char type;
        // Enemy ID
        u_char dat_no;
        // Action number?
        u_char act_no;
        // I prefer Naruto myself :D
        u_char anime_no;

        MOVE_BOX move_box;
        ENE_DAT *dat;
        MPOS mpos;
        LIGHT_PACK mylight;
        float dist_p_e;
        float dist_c_e;
        float pra_per;
        float pr_anime;
        u_short pra_time;
        u_short bloop;
        u_char bjob_no;
        u_char bpos_no;
        u_char bwait_time;
        u_char recog_tm;
        P_INT bcomm_add;
        long int bcomm_add_top;
        u_char tr_rate;
        u_char ajob_no;
        u_char apos_no;
        u_char await_time;
        P_INT acomm_add;
        long int acomm_add_top;
        void *pdf;
        float d_pd;
        void *pdf2;
        float d_pd2;
        void *nee;
        float nee_rate;
        float nee_size;
        u_int nee_col;
        int se_omen[1];
        sceVu0FVECTOR adjp;
        sceVu0FVECTOR pp;
        sceVu0FVECTOR sp;
        sceVu0FVECTOR si;
        sceVu0FVECTOR bep;
        u_short in_finder_tm;
        u_char area[1];
        u_short tr_time;
        u_char tr_max;
        u_char dmg_type;
        u_char room_no;
        u_char se_area_no;
        u_char ani_reso;
        u_char ani_reso_tm;
        short int fp[1];
        short int fp2[1][1];
        u_char eroot[1];
        u_char plight_svo;
        u_char slight_svo;
        u_char plight_svm[1];
        u_char slight_svm[1];
        float pa_radius;
        AENE_INFO_DAT *aie;
        u_short stm_slow;
        u_short stm_view;
        u_short stm_stop;
        u_char tr_rate2;

        void Print()
        {
            printf("ENE_WRK: \n");
            printf("sta: %u\n", sta);
            printf("sta2: %u\n", sta2);
            printf("hp: %u\n", hp);
            printf("dmg %u\n", dmg);
            printf("dmg_old %u\n", dmg_old);
            printf("atk_tm %u\n", atk_tm);
            printf("type %u\n", (uint8_t)type);
            printf("dat_no %u\n", (uint8_t)dat_no);
            printf("act_no %u\n", (uint8_t)act_no);
            printf("anime_no %u\n", (uint8_t)anime_no);
            move_box.Print();
            // printf("dat", *e.dat);
            mpos.Print();
            mylight.Print();
            printf("dist_p_e: %f\n", dist_p_e);
            printf("dist_c_e: %f\n", dist_c_e);
            printf("pra_per: %f\n", pra_per);
            printf("pr_anime: %f\n", pr_anime);
            printf("pra_time: %u\n", pra_time);
            printf("bloop: %u\n", bloop);
            printf("bjob_no: %u\n", (uint8_t)bjob_no);
            printf("bpos_no: %u\n", (uint8_t)bpos_no);
            printf("bwait_time: %u\n", (uint8_t)bwait_time);
            printf("recog_tm: %u\n", (uint8_t)recog_tm);
            printf("bcom_add_top: %ld\n", bcomm_add_top);
            printf("tr_rate: %u\n", (uint8_t)tr_rate);
            printf("ajob_no: %u\n", (uint8_t)ajob_no);
            printf("apos_no: %u\n", (uint8_t)apos_no);
            printf("await_time: %u\n", (uint8_t)await_time);
            printf("acomm_add_top: %ld\n", acomm_add_top);
            printf("d_pd: %f\n", d_pd);
            printf("d_pd2: %f\n", d_pd2);
            printf("nee_rate: %f\n", nee_rate);
            printf("nee_size: %f\n", nee_size);
            printf("nee_col: %u\n", nee_col);
            printf("se_omen: %d\n", se_omen[0]);
            printf("\n");
            printf("Adjp: \n");
            adjp.Print();
            printf("PP: \n");
            pp.Print();
            printf("Sp: \n");
            sp.Print();
            printf("Si: \n");
            si.Print();
            printf("Bep: \n");
            bep.Print();
            printf("\n");
            printf("in_finder_tm: %u\n", in_finder_tm);
            printf("area 0: %u\n", (uint8_t)area[0]);
            printf("area 1: %u\n", (uint8_t)area[1]);
            printf("tr_time: %u\n", tr_time);
            printf("tr_max: %u\n", (uint8_t)tr_max);
            printf("dmg_type: %u\n", (uint8_t)dmg_type);
            printf("room_no: %u\n", (uint8_t)room_no);
            printf("se_area_no: %u\n", (uint8_t)se_area_no);
            printf("ani_reso: %u\n", (uint8_t)ani_reso);
            printf("ani_reso_tm: %u\n", (uint8_t)ani_reso_tm);
            printf("fp: %u\n", fp[0]);
            printf("fp2: %u\n", fp2[0][0]);
            printf("eroot: %u\n", (uint8_t)eroot[0]);
            printf("plight_svo: %u\n", (uint8_t)plight_svo);
            printf("slight_svo: %u\n", (uint8_t)slight_svo);
            printf("plight_svm: %u\n", (uint8_t)plight_svm[0]);
            printf("slight_svm: %u\n", (uint8_t)slight_svm[0]);
            printf("pa_radius: %f\n", pa_radius);
            // printf("aie", *aie);
            printf("stm_slow: %u\n", stm_slow);
            printf("stm_view: %u\n", stm_view);
            printf("stm_stop: %u\n", stm_stop);
            printf("tr_rate2: %u\n", (uint8_t)tr_rate2);
        }
    };

    static void to_json(json &j, const ENE_WRK &e)
    {
        j = json{{"sta", e.sta},
                 {"sta2", e.sta2},
                 {"hp", e.hp},
                 {"dmg", e.dmg},
                 {"dmg_old", e.dmg_old},
                 {"atk_tm", e.atk_tm},
                 {"type", e.type},
                 {"dat_no", e.dat_no},
                 {"act_no", e.act_no},
                 {"anime_no", e.anime_no},
                 {"move_box", e.move_box},
                 //{"dat", *e.dat},
                 {"mpos", e.mpos},
                 {"mylight", e.mylight},
                 {"dist_p_e", e.dist_p_e},
                 {"dist_c_e", e.dist_c_e},
                 {"pra_per", e.pra_per},
                 {"pr_anime", e.pr_anime},
                 {"pra_time", e.pra_time},
                 {"bloop", e.bloop},
                 {"bjob_no", e.bjob_no},
                 {"bpos_no", e.bpos_no},
                 {"bwait_time", e.bwait_time},
                 {"recog_tm", e.recog_tm},
                 {"bcom_add_top", e.bcomm_add_top},
                 {"tr_rate", e.tr_rate},
                 {"ajob_no", e.ajob_no},
                 {"apos_no", e.apos_no},
                 {"await_time", e.await_time},
                 {"acomm_add_top", e.acomm_add_top},
                 {"d_pd", e.d_pd},
                 {"d_pd2", e.d_pd2},
                 {"nee_rate", e.nee_rate},
                 {"nee_size", e.nee_size},
                 {"nee_col", e.nee_col},
                 {"se_omen", e.se_omen},
                 {"adjp", e.adjp},
                 {"pp", e.pp},
                 {"sp", e.sp},
                 {"si", e.si},
                 {"bep", e.bep},
                 {"in_finder_tm", e.in_finder_tm},
                 {"area", e.area},
                 {"tr_time", e.tr_time},
                 {"tr_max", e.tr_max},
                 {"dmg_type", e.dmg_type},
                 {"room_no", e.room_no},
                 {"se_area_no", e.se_area_no},
                 {"ani_reso", e.ani_reso},
                 {"ani_reso_tm", e.ani_reso_tm},
                 {"fp", e.fp},
                 {"fp2", e.fp2},
                 {"eroot", e.eroot},
                 {"plight_svo", e.plight_svo},
                 {"slight_svo", e.slight_svo},
                 {"plight_svm", e.plight_svm},
                 {"slight_svm", e.slight_svm},
                 {"pa_radius", e.pa_radius},
                 //{"aie", *e.aie},
                 {"stm_slow", e.stm_slow},
                 {"stm_view", e.stm_view},
                 {"stm_stop", e.stm_stop},
                 {"tr_rate2", e.tr_rate2}};
    }
    typedef struct
    {
        u_char se_foot;
        u_char room_no;
        u_char room_old;
        u_char pad;
        u_short camera_no;
        u_short camera_no_old;
        u_short camera_btl;
        u_short camera_btl_old;
        u_short camera_drm;
        u_short camera_drm_old;
        u_short camera_door;
        u_short camera_door_old;
        u_short camera_door_did;
        u_char camera_door_rid;
        u_char cam_type;
        float hight;
    } PROOM_INFO;

    typedef struct
    {
        u_short door_id;
        u_char flag;
        u_char room_no;
        sceVu0FVECTOR dov;
    } DOPEN_POS;

    enum
    {
        PMODE_NORMAL = 0,
        PMODE_FINDER = 1,
        PMODE_DMG = 2,
        PMODE_FINDER_END = 3,
        PMODE_MSG_DISP = 4,
        PMODE_POSE = 5,
        PMODE_FINDER_IN = 6,
        PMODE_PRE_DMG = 7,
        PMODE_OVERHEAT = 8,
        PMODE_FIN_CAM = 9,
        PMODE_ANIME = 10
    };

    std::map<u_char, const char *> PMODE_MAP{
        {0, "PMODE_NORMAL"},
        {1, "PMODE_FINDER"},
        {2, "PMODE_DMG"},
        {3, "PMODE_FINDER_END"},
        {4, "PMODE_MSG_DISP"},
        {5, "PMODE_POSE"},
        {6, "PMODE_FINDER_IN"},
        {7, "PMODE_PRE_DMG"},
        {8, "PMODE_OVERHEAT"},
        {9, "PMODE_FIN_CAM"},
        {10, "PMODE_ANIME"}};

    struct PLYR_WRK
    {
        u_int sta;
        u_int mvsta;
        u_char mode;
        u_char cam_type;
        u_char anime_no;
        u_char cond;
        u_short cond_tm;
        u_short flash_tm;
        u_short aphoto_tm;
        u_short dmg;
        u_short hp;
        u_short ap_timer;
        u_short dwalk_tm;
        u_short fh_no;
        float fh_deg;
        float spd;
        float spd_ud;
        float prot;
        float frot_x;
        float charge_deg;
        float charge_rate;
        u_char charge_num;
        u_char rock_trgt;
        u_char film_no;
        u_char dmg_cam_flag;
        u_char hp_num;
        u_char mode_save;
        u_char move_mot;
        u_char atk_no;
        u_char near_ene_no;
        u_char photo_charge;
        u_char dmg_type;
        u_char spe1_dir;
        char pr_set;
        char po_set;
        u_char reserve[1];
        sceVu0FVECTOR mv;
        sceVu0FVECTOR op;
        sceVu0FVECTOR rock_adj;
        sceVu0FVECTOR bwp;
        sceVu0FVECTOR cp_old;
        sceVu0FVECTOR soulp;
        sceVu0FVECTOR spot_rot;
        sceVu0FVECTOR spot_pos;
        sceVu0FVECTOR shadow_direction;
        sceVu0FVECTOR psave;
        sceVu0FVECTOR fhp[1];
        short int fp[1];
        MOVE_BOX move_box;
        LIGHT_PACK mylight;
        PROOM_INFO pr_info;
        DOPEN_POS dop;
        int se_deadly;
        u_int padding;

        void Print()
        {
            printf("Sta: %04x\n", sta);
            printf("Mvsta: %04x\n", mvsta);
            printf("Mode: %s\n", PMODE_MAP[mode]);
            printf("Cam_type: %03du\n", (uint8_t)cam_type);
            printf("Anime_No: %03du\n", (uint8_t)anime_no);
            printf("Cond: %03du\n", (uint8_t)cond);
            printf("Cond_tm: %u\n", cond_tm);
            printf("Flash_tm: %d\n", flash_tm);
            printf("Aphoto_tm: %u\n", aphoto_tm);
            printf("Dmg: %u\n", dmg);
            printf("Hp: %u\n", hp);
            printf("Ap_Timer: %u\n", ap_timer);
            printf("Dwalk_Tm: %u\n", dwalk_tm);
            printf("Fh_No: %u\n", fh_no);
            printf("Fh_deg: %f\n", fh_deg);
            printf("Spd: %f\n", spd);
            printf("Spd_Ud: %f\n", spd_ud);
            printf("Prot: %f\n", prot);
            printf("Frot_X: %f\n", frot_x);
            printf("Charge_Deg: %f\n", charge_deg);
            printf("Charge_Rate: %f\n", charge_rate);
            printf("Charge_Rate: %03du\n", (uint8_t)charge_num);
            printf("Rock_Trgt: %03du\n", (uint8_t)rock_trgt);
            printf("Film_No: %03du\n", (uint8_t)film_no);
            printf("Dmg_Cam_Flg: %03du\n", (uint8_t)dmg_cam_flag);
            printf("Hp_Num: %03du\n", (uint8_t)hp_num);
            printf("Mode_Save: %03du\n", (uint8_t)mode_save);
            printf("Move_Mot: %03du\n", (uint8_t)move_mot);
            printf("Atk_No: %03du\n", (uint8_t)atk_no);
            printf("Near_Ene_No: %03du\n", (uint8_t)near_ene_no);
            printf("Photo_Charge: %03du\n", (uint8_t)photo_charge);
            printf("Dmg_Type: %03du\n", (uint8_t)dmg_type);
            printf("Spe1_dir: %03du\n", (uint8_t)spe1_dir);
            printf("Pr_Set: %u\n", pr_set);
            printf("Po_Set: %u\n", po_set);
            fflush(stdout);
            printf("\033[0;0H");
        }
    };

    static void to_json(json &j, const PLYR_WRK &p)
    {
        j = json{{"sta", p.sta},
                 {"mvsta", p.mvsta},
                 {"mode", p.mode},
                 {"cam_type", p.cam_type},
                 {"anime_no", p.anime_no},
                 {"cond", p.cond},
                 {"cond_tm", p.cond_tm},
                 {"flash_tm", p.flash_tm},
                 {"aphoto_tm", p.aphoto_tm},
                 {"dmg", p.dmg},
                 {"hp", p.hp},
                 {"ap_timer", p.ap_timer},
                 {"dwalk_tm", p.dwalk_tm},
                 {"fh_no", p.fh_no},
                 {"fh_deg", p.fh_deg},
                 {"spd", p.spd},
                 {"spd_ud", p.spd_ud},
                 {"prot", p.prot},
                 {"frot_x", p.frot_x},
                 {"charge_deg", p.charge_deg},
                 {"charge_rate", p.charge_rate},
                 {"charge_num", p.charge_num},
                 {"rock_trgt", p.rock_trgt},
                 {"film_no", p.film_no},
                 {"dmg_cam_flag", p.dmg_cam_flag},
                 {"hp_num", p.hp_num},
                 {"mode_save", p.mode_save},
                 {"move_mot", p.move_mot},
                 {"atk_no", p.atk_no},
                 {"near_ene_no", p.near_ene_no},
                 {"photo_charge", p.photo_charge},
                 {"dmg_type", p.dmg_type},
                 {"spe1_dir", p.spe1_dir},
                 {"pr_set", p.pr_set},
                 {"po_set", p.po_set},
                 {"mv", p.mv},
                 {"op", p.op},
                 {"rock_adj", p.rock_adj},
                 {"bwp", p.bwp},
                 {"cp_old", p.cp_old},
                 {"soulp", p.soulp},
                 {"spot_rot", p.spot_rot},
                 {"spot_pos", p.spot_pos},
                 {"shadow_direction", p.shadow_direction},
                 {"psave", p.psave},
                 {"fhp", p.fhp},
                 {"fp", p.fp},
                 {"move_box", p.move_box},
                 {"mylight", p.mylight}};
    }

    struct EVENT_WRK
    {
        u_char mode;
        u_char evt_no;
        u_char movie_on;
        u_char next_msn;
        u_char msg_init;
        u_char use_item;
        u_char get_item;
        u_char btl_ene;
        u_char end_ev;
        u_char btl_lock;
        u_char pht_2d;
        u_char pht_furn;
        u_char pht_ev[1];
        u_char pos_req[1];
        u_char spev_tmp[1];
        u_char gst_door[1];
        u_char face_stts[1];

        void Print()
        {
            printf("EVENT_WRK: \n");
            printf("Mode: %03u\n", (uint8_t)mode);
            printf("Evt_No: %03u\n", (uint8_t)evt_no);
            printf("Movie_On: %02X\n", (uint8_t)movie_on);
            printf("Next_Msn: %03u\n", (uint8_t)next_msn);
            printf("Msg_Init: %03u\n", (uint8_t)msg_init);
            printf("Use_Item: %03u\n", (uint8_t)use_item);
            printf("Get_Item: %03u\n", (uint8_t)get_item);
            printf("Btl_Ene: %03u\n", (uint8_t)btl_ene);
            printf("End_Ev: %03u\n", (uint8_t)end_ev);
            printf("Btl_Lock: %03u\n", (uint8_t)btl_lock);
            printf("Pht_2D: %03u\n", (uint8_t)pht_2d);
            printf("Pht_Furn: %03u\n", (uint8_t)pht_furn);
            printf("Pht_Ev: %03u\n", (uint8_t)*pht_ev);
            printf("Pos_Req: %03u\n", (uint8_t)*pos_req);
            printf("Spev_Tmp: %03u\n", (uint8_t)*pos_req);
            printf("Gst_Door: %03u\n", (uint8_t)*gst_door);
            printf("Face_Stts: %03u\n", (uint8_t)*face_stts);
        }
    };

} // namespace FatalData