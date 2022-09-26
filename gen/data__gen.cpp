#include "data__gen.hpp"

namespace lang::data::lexer {
    rc_ptr<lang_rt::DFALabelIdVec> label_ids_ascii() {
        auto ret = Vec<lang_rt::DFALabelId>::repeat(lang_rt::DFATable::NO_LABEL, 128);
        ret->at_unchecked(0) = 1;
        ret->at_unchecked(1) = 1;
        ret->at_unchecked(2) = 1;
        ret->at_unchecked(3) = 1;
        ret->at_unchecked(4) = 1;
        ret->at_unchecked(5) = 1;
        ret->at_unchecked(6) = 1;
        ret->at_unchecked(7) = 1;
        ret->at_unchecked(8) = 1;
        ret->at_unchecked(9) = 1;
        ret->at_unchecked(10) = 2;
        ret->at_unchecked(11) = 3;
        ret->at_unchecked(12) = 3;
        ret->at_unchecked(13) = 3;
        ret->at_unchecked(14) = 3;
        ret->at_unchecked(15) = 3;
        ret->at_unchecked(16) = 3;
        ret->at_unchecked(17) = 3;
        ret->at_unchecked(18) = 3;
        ret->at_unchecked(19) = 3;
        ret->at_unchecked(20) = 3;
        ret->at_unchecked(21) = 3;
        ret->at_unchecked(22) = 3;
        ret->at_unchecked(23) = 3;
        ret->at_unchecked(24) = 3;
        ret->at_unchecked(25) = 3;
        ret->at_unchecked(26) = 3;
        ret->at_unchecked(27) = 3;
        ret->at_unchecked(28) = 3;
        ret->at_unchecked(29) = 3;
        ret->at_unchecked(30) = 3;
        ret->at_unchecked(31) = 3;
        ret->at_unchecked(32) = 4;
        ret->at_unchecked(33) = 5;
        ret->at_unchecked(34) = 6;
        ret->at_unchecked(35) = 7;
        ret->at_unchecked(36) = 8;
        ret->at_unchecked(37) = 8;
        ret->at_unchecked(38) = 8;
        ret->at_unchecked(39) = 8;
        ret->at_unchecked(40) = 9;
        ret->at_unchecked(41) = 10;
        ret->at_unchecked(42) = 11;
        ret->at_unchecked(43) = 11;
        ret->at_unchecked(44) = 12;
        ret->at_unchecked(45) = 13;
        ret->at_unchecked(46) = 14;
        ret->at_unchecked(47) = 15;
        ret->at_unchecked(48) = 16;
        ret->at_unchecked(49) = 16;
        ret->at_unchecked(50) = 16;
        ret->at_unchecked(51) = 16;
        ret->at_unchecked(52) = 16;
        ret->at_unchecked(53) = 16;
        ret->at_unchecked(54) = 16;
        ret->at_unchecked(55) = 16;
        ret->at_unchecked(56) = 16;
        ret->at_unchecked(57) = 16;
        ret->at_unchecked(58) = 17;
        ret->at_unchecked(59) = 18;
        ret->at_unchecked(60) = 19;
        ret->at_unchecked(61) = 20;
        ret->at_unchecked(62) = 20;
        ret->at_unchecked(63) = 20;
        ret->at_unchecked(64) = 20;
        ret->at_unchecked(65) = 21;
        ret->at_unchecked(66) = 21;
        ret->at_unchecked(67) = 21;
        ret->at_unchecked(68) = 21;
        ret->at_unchecked(69) = 21;
        ret->at_unchecked(70) = 21;
        ret->at_unchecked(71) = 21;
        ret->at_unchecked(72) = 21;
        ret->at_unchecked(73) = 21;
        ret->at_unchecked(74) = 21;
        ret->at_unchecked(75) = 21;
        ret->at_unchecked(76) = 21;
        ret->at_unchecked(77) = 21;
        ret->at_unchecked(78) = 21;
        ret->at_unchecked(79) = 21;
        ret->at_unchecked(80) = 21;
        ret->at_unchecked(81) = 21;
        ret->at_unchecked(82) = 21;
        ret->at_unchecked(83) = 21;
        ret->at_unchecked(84) = 22;
        ret->at_unchecked(85) = 23;
        ret->at_unchecked(86) = 23;
        ret->at_unchecked(87) = 23;
        ret->at_unchecked(88) = 23;
        ret->at_unchecked(89) = 23;
        ret->at_unchecked(90) = 23;
        ret->at_unchecked(91) = 24;
        ret->at_unchecked(92) = 24;
        ret->at_unchecked(93) = 24;
        ret->at_unchecked(94) = 25;
        ret->at_unchecked(95) = 26;
        ret->at_unchecked(96) = 27;
        ret->at_unchecked(97) = 28;
        ret->at_unchecked(98) = 29;
        ret->at_unchecked(99) = 30;
        ret->at_unchecked(100) = 31;
        ret->at_unchecked(101) = 32;
        ret->at_unchecked(102) = 33;
        ret->at_unchecked(103) = 34;
        ret->at_unchecked(104) = 35;
        ret->at_unchecked(105) = 36;
        ret->at_unchecked(106) = 37;
        ret->at_unchecked(107) = 37;
        ret->at_unchecked(108) = 38;
        ret->at_unchecked(109) = 39;
        ret->at_unchecked(110) = 40;
        ret->at_unchecked(111) = 41;
        ret->at_unchecked(112) = 42;
        ret->at_unchecked(113) = 43;
        ret->at_unchecked(114) = 44;
        ret->at_unchecked(115) = 45;
        ret->at_unchecked(116) = 46;
        ret->at_unchecked(117) = 47;
        ret->at_unchecked(118) = 48;
        ret->at_unchecked(119) = 49;
        ret->at_unchecked(120) = 50;
        ret->at_unchecked(121) = 51;
        ret->at_unchecked(122) = 52;
        ret->at_unchecked(123) = 53;
        ret->at_unchecked(124) = 54;
        ret->at_unchecked(125) = 55;
        ret->at_unchecked(126) = 56;
        ret->at_unchecked(127) = 56;
        return ret;
    }
}

namespace lang::data::lexer {
    rc_ptr<lang_rt::DFALabelIdMap> label_ids_unicode() {
        auto ret = make_rc<lang_rt::DFALabelIdMap>();
        ret->insert(make_pair(128, 56));
        ret->insert(make_pair(1114112, 57));
        return ret;
    }
}

namespace lang::data::lexer::body {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl) {
        static const u16_array tt = {0x0004, 0xffff, 0x0002, 0xffff, 0x0001, 0xffff, 0x0017, 0x0016, 0xffff, 0x000a, 0x000b, 0xffff, 0x000c, 0xffff, 0x0005, 0x0003, 0xffff, 0x0006, 0x0007, 0x000e, 0xffff, 0x0018, 0x0012, 0x0018, 0xffff, 0x000d, 0x0019, 0xffff, 0x0018, 0x0018, 0x0018, 0x000f, 0x0010, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0013, 0x0011, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0015, 0x0018, 0x0014, 0x0018, 0x0018, 0x0008, 0xffff, 0x0009, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001a, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001b, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001d, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0020, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x0021, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0022, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0023, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0024, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0025, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0026, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0027, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0028, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x002a, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x002b, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x002c, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x002d, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x002e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x002f, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0030, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0031, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0032, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0028, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0x0029, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0033, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x0034, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0035, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x0036, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0037, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0038, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0039, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x003a, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x003b, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x003c, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x003d, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x003e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x003f, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0040, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0041, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x0042, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x0043, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0044, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x0045, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0046, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x0047, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0x001f, 0xffff, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0xffff, 0xffff, 0xffff, 0xffff};
        return static_cast<i16>(tt[v * 57 + lbl]);
    }
}

namespace lang::data::lexer::body {
    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v) {
        switch (v) {
            case 0: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 1: {
                return make_pair(1, lang_rt::NO_TOKEN);
            }
            case 2: {
                return make_pair(1, lang_rt::NO_TOKEN);
            }
            case 3: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 4: {
                return make_pair(3, lang_rt::NO_TOKEN);
            }
            case 5: {
                return make_pair(0, 1);
            }
            case 6: {
                return make_pair(0, 2);
            }
            case 7: {
                return make_pair(0, 3);
            }
            case 8: {
                return make_pair(0, 5);
            }
            case 9: {
                return make_pair(0, 6);
            }
            case 10: {
                return make_pair(0, 7);
            }
            case 11: {
                return make_pair(0, 8);
            }
            case 12: {
                return make_pair(0, 9);
            }
            case 13: {
                return make_pair(0, 10);
            }
            case 14: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 15: {
                return make_pair(0, 0);
            }
            case 16: {
                return make_pair(0, 0);
            }
            case 17: {
                return make_pair(0, 0);
            }
            case 18: {
                return make_pair(0, 0);
            }
            case 19: {
                return make_pair(0, 0);
            }
            case 20: {
                return make_pair(0, 0);
            }
            case 21: {
                return make_pair(0, 0);
            }
            case 22: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 23: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 24: {
                return make_pair(0, 0);
            }
            case 25: {
                return make_pair(0, 0);
            }
            case 26: {
                return make_pair(2, lang_rt::NO_TOKEN);
            }
            case 27: {
                return make_pair(0, 4);
            }
            case 28: {
                return make_pair(0, 11);
            }
            case 29: {
                return make_pair(0, 0);
            }
            case 30: {
                return make_pair(0, 0);
            }
            case 31: {
                return make_pair(0, 0);
            }
            case 32: {
                return make_pair(0, 0);
            }
            case 33: {
                return make_pair(0, 0);
            }
            case 34: {
                return make_pair(0, 0);
            }
            case 35: {
                return make_pair(0, 0);
            }
            case 36: {
                return make_pair(0, 0);
            }
            case 37: {
                return make_pair(0, 0);
            }
            case 38: {
                return make_pair(0, 0);
            }
            case 39: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 40: {
                return make_pair(0, 21);
            }
            case 41: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 42: {
                return make_pair(0, 12);
            }
            case 43: {
                return make_pair(0, 0);
            }
            case 44: {
                return make_pair(0, 0);
            }
            case 45: {
                return make_pair(0, 0);
            }
            case 46: {
                return make_pair(0, 0);
            }
            case 47: {
                return make_pair(0, 16);
            }
            case 48: {
                return make_pair(0, 0);
            }
            case 49: {
                return make_pair(0, 0);
            }
            case 50: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 51: {
                return make_pair(0, 13);
            }
            case 52: {
                return make_pair(0, 0);
            }
            case 53: {
                return make_pair(0, 0);
            }
            case 54: {
                return make_pair(0, 15);
            }
            case 55: {
                return make_pair(0, 0);
            }
            case 56: {
                return make_pair(0, 0);
            }
            case 57: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 58: {
                return make_pair(0, 0);
            }
            case 59: {
                return make_pair(0, 0);
            }
            case 60: {
                return make_pair(0, 17);
            }
            case 61: {
                return make_pair(0, 18);
            }
            case 62: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 63: {
                return make_pair(0, 0);
            }
            case 64: {
                return make_pair(0, 0);
            }
            case 65: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 66: {
                return make_pair(0, 0);
            }
            case 67: {
                return make_pair(0, 20);
            }
            case 68: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 69: {
                return make_pair(0, 0);
            }
            case 70: {
                return make_pair(0, 19);
            }
            case 71: {
                return make_pair(0, 14);
            }
            default: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
        }
    }
}

namespace lang::data::lexer::body {
    __attribute__((always_inline)) IntPair step_exec(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi) {
        auto ret = make_pair(-1, -1);
        bool mode_switch = false;
        switch (acc) {
            case 0: {
                st->enqueue_emit_ext(emit_dst, ws_state, tok, tok_lo, tok_hi, true);
                in_i = tok_hi;
                break;
            }
            case 1: {
                in_i = tok_hi;
                break;
            }
            case 2: {
                ret = make_pair(1, in_i);
                mode_switch = true;
                break;
            }
            case 3: {
                ret = make_pair(lang_rt::DFATable::NEW_MODE_POP, -1);
                mode_switch = true;
                break;
            }
            default: {
                AX();
            }
        }
        return ret;
    }
}

namespace lang::data::lexer::comment_single {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl) {
        static const u16_array tt = {0xffff, 0x0002, 0x0001, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff};
        return static_cast<i16>(tt[v * 57 + lbl]);
    }
}

namespace lang::data::lexer::comment_single {
    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v) {
        switch (v) {
            case 0: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
            case 1: {
                return make_pair(0, lang_rt::NO_TOKEN);
            }
            case 2: {
                return make_pair(1, lang_rt::NO_TOKEN);
            }
            default: {
                return make_pair(lang_rt::DFATable::NO_ACTION, lang_rt::NO_TOKEN);
            }
        }
    }
}

namespace lang::data::lexer::comment_single {
    __attribute__((always_inline)) IntPair step_exec(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi) {
        auto ret = make_pair(-1, -1);
        bool mode_switch = false;
        switch (acc) {
            case 0: {
                ret = make_pair(lang_rt::DFATable::NEW_MODE_POP_EXTRACT, -1);
                mode_switch = true;
                break;
            }
            case 1: {
                in_i = tok_hi;
                break;
            }
            default: {
                AX();
            }
        }
        return ret;
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node_T x) {
    switch (x->w_) {
        case lang::data::Node::_W::Module: {
            pr_debug(os, flags, x->as_Module());
            break;
        }
        case lang::data::Node::_W::Param: {
            pr_debug(os, flags, x->as_Param());
            break;
        }
        case lang::data::Node::_W::Field: {
            pr_debug(os, flags, x->as_Field());
            break;
        }
        case lang::data::Node::_W::SumId: {
            pr_debug(os, flags, x->as_SumId());
            break;
        }
        case lang::data::Node::_W::Id: {
            pr_debug(os, flags, x->as_Id());
            break;
        }
        case lang::data::Node::_W::Decl: {
            pr_debug(os, flags, x->as_Decl());
            break;
        }
        case lang::data::Node::_W::Mod: {
            pr_debug(os, flags, x->as_Mod());
            break;
        }
        case lang::data::Node::_W::Expr: {
            pr_debug(os, flags, x->as_Expr());
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node::_T::~_T() {
}

lang::data::Node::_T::_T(lang::data::Node::_W w) {
    w_ = w;
}

bool lang::data::Node::_T::is_Module() {
    return w_ == lang::data::Node::_W::Module;
}

bool lang::data::Node::_T::is_Param() {
    return w_ == lang::data::Node::_W::Param;
}

bool lang::data::Node::_T::is_Field() {
    return w_ == lang::data::Node::_W::Field;
}

bool lang::data::Node::_T::is_SumId() {
    return w_ == lang::data::Node::_W::SumId;
}

bool lang::data::Node::_T::is_Id() {
    return w_ == lang::data::Node::_W::Id;
}

bool lang::data::Node::_T::is_Decl() {
    return w_ == lang::data::Node::_W::Decl;
}

bool lang::data::Node::_T::is_Mod() {
    return w_ == lang::data::Node::_W::Mod;
}

bool lang::data::Node::_T::is_Expr() {
    return w_ == lang::data::Node::_W::Expr;
}

lang::data::Node::Module_T lang::data::Node::_T::as_Module() {
    AT(this->is_Module());
    return this->rc_from_this_poly<lang::data::Node::Module::_T>();
}

lang::data::Node::Param_T lang::data::Node::_T::as_Param() {
    AT(this->is_Param());
    return this->rc_from_this_poly<lang::data::Node::Param::_T>();
}

lang::data::Node::Field_T lang::data::Node::_T::as_Field() {
    AT(this->is_Field());
    return this->rc_from_this_poly<lang::data::Node::Field::_T>();
}

lang::data::Node::SumId_T lang::data::Node::_T::as_SumId() {
    AT(this->is_SumId());
    return this->rc_from_this_poly<lang::data::Node::SumId::_T>();
}

lang::data::Node::Id_T lang::data::Node::_T::as_Id() {
    AT(this->is_Id());
    return this->rc_from_this_poly<lang::data::Node::Id::_T>();
}

lang::data::Node::Decl_T lang::data::Node::_T::as_Decl() {
    AT(this->is_Decl());
    return this->rc_from_this_poly<lang::data::Node::Decl::_T>();
}

lang::data::Node::Mod_T lang::data::Node::_T::as_Mod() {
    AT(this->is_Mod());
    return this->rc_from_this_poly<lang::data::Node::Mod::_T>();
}

lang::data::Node::Expr_T lang::data::Node::_T::as_Expr() {
    AT(this->is_Expr());
    return this->rc_from_this_poly<lang::data::Node::Expr::_T>();
}

void lang::data::Node::_T::hash_ser_acc_lang_data_Node(SerBuf& buf) const {
    hash_ser(buf, static_cast<Int>(w_));
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Module_T x) {
    os << "lang::data::Node::Module {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "decls: ";
    pr_debug(os, flags.sub_lo(), x->decls_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Module::_T::_T() : lang::data::Node::_T(lang::data::Node::_W::Module) {
}

__attribute__((always_inline)) lang::data::Node::Module_T lang::data::Node::Module::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::data::Node::Decl_T> decls) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->decls_ = decls;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Module_T lang::data::Node::Module::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::data::Node::Decl_T> decls) {
    auto ret1 = make_rc_ext<lang::data::Node::Module::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->decls_ = decls;
    return ret1;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->decls_ = this->decls_;
    return ret;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->decls_ = this->decls_;
    return ret;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->decls_ = this->decls_;
    return ret;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->decls_ = this->decls_;
    return ret;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->decls_ = this->decls_;
    return ret;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->decls_ = this->decls_;
    return ret;
}

lang::data::Node::Module_T lang::data::Node::Module::_T::with_decls(Vec_T<lang::data::Node::Decl_T> decls) {
    auto ret = make_rc<lang::data::Node::Module::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->decls_ = decls;
    return ret;
}

void lang::data::Node::Module::_T::hash_ser_acc_lang_data_Node_Module(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, decls_);
}

void lang::data::Node::Module::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Module::_T::hash_ser_acc_lang_data_Node_Module(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Param_T x) {
    os << "lang::data::Node::Param {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "name: ";
    pr_debug(os, flags.sub_lo(), x->name_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "type_: ";
    pr_debug(os, flags.sub_lo(), x->type__);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Param::_T::_T() : lang::data::Node::_T(lang::data::Node::_W::Param) {
}

__attribute__((always_inline)) lang::data::Node::Param_T lang::data::Node::Param::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::data::Node::Expr_T type_) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->name_ = name;
    ret->type__ = type_;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Param_T lang::data::Node::Param::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::data::Node::Expr_T type_) {
    auto ret1 = make_rc_ext<lang::data::Node::Param::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->name_ = name;
    ret1->type__ = type_;
    return ret1;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->name_ = this->name_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_name(StrSlice name) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = name;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Param_T lang::data::Node::Param::_T::with_type_(lang::data::Node::Expr_T type_) {
    auto ret = make_rc<lang::data::Node::Param::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->type__ = type_;
    return ret;
}

void lang::data::Node::Param::_T::hash_ser_acc_lang_data_Node_Param(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, name_);
    hash_ser(buf, type__);
}

void lang::data::Node::Param::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Param::_T::hash_ser_acc_lang_data_Node_Param(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Field_T x) {
    os << "lang::data::Node::Field {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "name: ";
    pr_debug(os, flags.sub_lo(), x->name_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "no_hash_: ";
    pr_debug(os, flags.sub_lo(), x->no_hash__);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "type_: ";
    pr_debug(os, flags.sub_lo(), x->type__);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Field::_T::_T() : lang::data::Node::_T(lang::data::Node::_W::Field) {
}

__attribute__((always_inline)) lang::data::Node::Field_T lang::data::Node::Field::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, bool no_hash_, lang::data::Node::Expr_T type_) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->name_ = name;
    ret->no_hash__ = no_hash_;
    ret->type__ = type_;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Field_T lang::data::Node::Field::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, bool no_hash_, lang::data::Node::Expr_T type_) {
    auto ret1 = make_rc_ext<lang::data::Node::Field::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->name_ = name;
    ret1->no_hash__ = no_hash_;
    ret1->type__ = type_;
    return ret1;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_name(StrSlice name) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = name;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_no_hash_(bool no_hash_) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = no_hash_;
    ret->type__ = this->type__;
    return ret;
}

lang::data::Node::Field_T lang::data::Node::Field::_T::with_type_(lang::data::Node::Expr_T type_) {
    auto ret = make_rc<lang::data::Node::Field::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->no_hash__ = this->no_hash__;
    ret->type__ = type_;
    return ret;
}

void lang::data::Node::Field::_T::hash_ser_acc_lang_data_Node_Field(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, name_);
    hash_ser(buf, no_hash__);
    hash_ser(buf, type__);
}

void lang::data::Node::Field::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Field::_T::hash_ser_acc_lang_data_Node_Field(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::SumId_T x) {
    os << "lang::data::Node::SumId {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "items: ";
    pr_debug(os, flags.sub_lo(), x->items_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::SumId::_T::_T() : lang::data::Node::_T(lang::data::Node::_W::SumId) {
}

__attribute__((always_inline)) lang::data::Node::SumId_T lang::data::Node::SumId::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->items_ = items;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::SumId_T lang::data::Node::SumId::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items) {
    auto ret1 = make_rc_ext<lang::data::Node::SumId::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->items_ = items;
    return ret1;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::SumId_T lang::data::Node::SumId::_T::with_items(Vec_T<StrSlice> items) {
    auto ret = make_rc<lang::data::Node::SumId::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = items;
    return ret;
}

void lang::data::Node::SumId::_T::hash_ser_acc_lang_data_Node_SumId(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, items_);
}

void lang::data::Node::SumId::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::SumId::_T::hash_ser_acc_lang_data_Node_SumId(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Id_T x) {
    os << "lang::data::Node::Id {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "items: ";
    pr_debug(os, flags.sub_lo(), x->items_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Id::_T::_T() : lang::data::Node::_T(lang::data::Node::_W::Id) {
}

__attribute__((always_inline)) lang::data::Node::Id_T lang::data::Node::Id::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->items_ = items;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Id_T lang::data::Node::Id::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items) {
    auto ret1 = make_rc_ext<lang::data::Node::Id::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->items_ = items;
    return ret1;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->items_ = this->items_;
    return ret;
}

lang::data::Node::Id_T lang::data::Node::Id::_T::with_items(Vec_T<StrSlice> items) {
    auto ret = make_rc<lang::data::Node::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->items_ = items;
    return ret;
}

void lang::data::Node::Id::_T::hash_ser_acc_lang_data_Node_Id(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, items_);
}

void lang::data::Node::Id::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Id::_T::hash_ser_acc_lang_data_Node_Id(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl_T x) {
    switch (x->w_) {
        case lang::data::Node::Decl::_W::Include: {
            pr_debug(os, flags, x->as_Include());
            break;
        }
        case lang::data::Node::Decl::_W::Namespace: {
            pr_debug(os, flags, x->as_Namespace());
            break;
        }
        case lang::data::Node::Decl::_W::Data: {
            pr_debug(os, flags, x->as_Data());
            break;
        }
        case lang::data::Node::Decl::_W::Enum: {
            pr_debug(os, flags, x->as_Enum());
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node::Decl::_T::~_T() {
}

lang::data::Node::Decl::_T::_T(lang::data::Node::Decl::_W w) : lang::data::Node::_T(lang::data::Node::_W::Decl) {
    w_ = w;
}

bool lang::data::Node::Decl::_T::is_Include() {
    return w_ == lang::data::Node::Decl::_W::Include;
}

bool lang::data::Node::Decl::_T::is_Namespace() {
    return w_ == lang::data::Node::Decl::_W::Namespace;
}

bool lang::data::Node::Decl::_T::is_Data() {
    return w_ == lang::data::Node::Decl::_W::Data;
}

bool lang::data::Node::Decl::_T::is_Enum() {
    return w_ == lang::data::Node::Decl::_W::Enum;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::_T::as_Include() {
    AT(this->is_Include());
    return this->rc_from_this_poly<lang::data::Node::Decl::Include::_T>();
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::_T::as_Namespace() {
    AT(this->is_Namespace());
    return this->rc_from_this_poly<lang::data::Node::Decl::Namespace::_T>();
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::_T::as_Data() {
    AT(this->is_Data());
    return this->rc_from_this_poly<lang::data::Node::Decl::Data::_T>();
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::_T::as_Enum() {
    AT(this->is_Enum());
    return this->rc_from_this_poly<lang::data::Node::Decl::Enum::_T>();
}

void lang::data::Node::Decl::_T::hash_ser_acc_lang_data_Node_Decl(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, static_cast<Int>(w_));
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod_T x) {
    switch (x->w_) {
        case lang::data::Node::Mod::_W::Mut: {
            pr_debug(os, flags, x->as_Mut());
            break;
        }
        case lang::data::Node::Mod::_W::Xform: {
            pr_debug(os, flags, x->as_Xform());
            break;
        }
        case lang::data::Node::Mod::_W::Visit: {
            pr_debug(os, flags, x->as_Visit());
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node::Mod::_T::~_T() {
}

lang::data::Node::Mod::_T::_T(lang::data::Node::Mod::_W w) : lang::data::Node::_T(lang::data::Node::_W::Mod) {
    w_ = w;
}

bool lang::data::Node::Mod::_T::is_Mut() {
    return w_ == lang::data::Node::Mod::_W::Mut;
}

bool lang::data::Node::Mod::_T::is_Xform() {
    return w_ == lang::data::Node::Mod::_W::Xform;
}

bool lang::data::Node::Mod::_T::is_Visit() {
    return w_ == lang::data::Node::Mod::_W::Visit;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::_T::as_Mut() {
    AT(this->is_Mut());
    return this->rc_from_this_poly<lang::data::Node::Mod::Mut::_T>();
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::_T::as_Xform() {
    AT(this->is_Xform());
    return this->rc_from_this_poly<lang::data::Node::Mod::Xform::_T>();
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::_T::as_Visit() {
    AT(this->is_Visit());
    return this->rc_from_this_poly<lang::data::Node::Mod::Visit::_T>();
}

void lang::data::Node::Mod::_T::hash_ser_acc_lang_data_Node_Mod(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, static_cast<Int>(w_));
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr_T x) {
    switch (x->w_) {
        case lang::data::Node::Expr::_W::Id: {
            pr_debug(os, flags, x->as_Id());
            break;
        }
        case lang::data::Node::Expr::_W::App: {
            pr_debug(os, flags, x->as_App());
            break;
        }
        case lang::data::Node::Expr::_W::Type_: {
            pr_debug(os, flags, x->as_Type_());
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node::Expr::_T::~_T() {
}

lang::data::Node::Expr::_T::_T(lang::data::Node::Expr::_W w) : lang::data::Node::_T(lang::data::Node::_W::Expr) {
    w_ = w;
}

bool lang::data::Node::Expr::_T::is_Id() {
    return w_ == lang::data::Node::Expr::_W::Id;
}

bool lang::data::Node::Expr::_T::is_App() {
    return w_ == lang::data::Node::Expr::_W::App;
}

bool lang::data::Node::Expr::_T::is_Type_() {
    return w_ == lang::data::Node::Expr::_W::Type_;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::_T::as_Id() {
    AT(this->is_Id());
    return this->rc_from_this_poly<lang::data::Node::Expr::Id::_T>();
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::_T::as_App() {
    AT(this->is_App());
    return this->rc_from_this_poly<lang::data::Node::Expr::App::_T>();
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::_T::as_Type_() {
    AT(this->is_Type_());
    return this->rc_from_this_poly<lang::data::Node::Expr::Type_::_T>();
}

void lang::data::Node::Expr::_T::hash_ser_acc_lang_data_Node_Expr(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node(buf);
    hash_ser(buf, static_cast<Int>(w_));
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Include_T x) {
    os << "lang::data::Node::Decl::Include {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "path: ";
    pr_debug(os, flags.sub_lo(), x->path_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Decl::Include::_T::_T() : lang::data::Node::Decl::_T(lang::data::Node::Decl::_W::Include) {
}

__attribute__((always_inline)) lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice path) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->path_ = path;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice path) {
    auto ret1 = make_rc_ext<lang::data::Node::Decl::Include::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->path_ = path;
    return ret1;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->path_ = this->path_;
    return ret;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->path_ = this->path_;
    return ret;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->path_ = this->path_;
    return ret;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->path_ = this->path_;
    return ret;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->path_ = this->path_;
    return ret;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->path_ = this->path_;
    return ret;
}

lang::data::Node::Decl::Include_T lang::data::Node::Decl::Include::_T::with_path(StrSlice path) {
    auto ret = make_rc<lang::data::Node::Decl::Include::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->path_ = path;
    return ret;
}

void lang::data::Node::Decl::Include::_T::hash_ser_acc_lang_data_Node_Decl_Include(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Decl(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, path_);
}

void lang::data::Node::Decl::Include::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Decl::Include::_T::hash_ser_acc_lang_data_Node_Decl_Include(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Namespace_T x) {
    os << "lang::data::Node::Decl::Namespace {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "name: ";
    pr_debug(os, flags.sub_lo(), x->name_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "body: ";
    pr_debug(os, flags.sub_lo(), x->body_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Decl::Namespace::_T::_T() : lang::data::Node::Decl::_T(lang::data::Node::Decl::_W::Namespace) {
}

__attribute__((always_inline)) lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<lang::data::Node::Decl_T> body) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->name_ = name;
    ret->body_ = body;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<lang::data::Node::Decl_T> body) {
    auto ret1 = make_rc_ext<lang::data::Node::Decl::Namespace::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->name_ = name;
    ret1->body_ = body;
    return ret1;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->name_ = this->name_;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_name(lang::data::Node::Id_T name) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = name;
    ret->body_ = this->body_;
    return ret;
}

lang::data::Node::Decl::Namespace_T lang::data::Node::Decl::Namespace::_T::with_body(Vec_T<lang::data::Node::Decl_T> body) {
    auto ret = make_rc<lang::data::Node::Decl::Namespace::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->body_ = body;
    return ret;
}

void lang::data::Node::Decl::Namespace::_T::hash_ser_acc_lang_data_Node_Decl_Namespace(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Decl(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, name_);
    hash_ser(buf, body_);
}

void lang::data::Node::Decl::Namespace::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Decl::Namespace::_T::hash_ser_acc_lang_data_Node_Decl_Namespace(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Data_T x) {
    os << "lang::data::Node::Decl::Data {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "name: ";
    pr_debug(os, flags.sub_lo(), x->name_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "base: ";
    pr_debug(os, flags.sub_lo(), x->base_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "params: ";
    pr_debug(os, flags.sub_lo(), x->params_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "mods: ";
    pr_debug(os, flags.sub_lo(), x->mods_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "fields: ";
    pr_debug(os, flags.sub_lo(), x->fields_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Decl::Data::_T::_T() : lang::data::Node::Decl::_T(lang::data::Node::Decl::_W::Data) {
}

__attribute__((always_inline)) lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::SumId_T name, Option_T<lang::data::Node::SumId_T> base, Option_T<Vec_T<lang::data::Node::Param_T>> params, Vec_T<lang::data::Node::Mod_T> mods, Vec_T<lang::data::Node::Field_T> fields) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->name_ = name;
    ret->base_ = base;
    ret->params_ = params;
    ret->mods_ = mods;
    ret->fields_ = fields;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::SumId_T name, Option_T<lang::data::Node::SumId_T> base, Option_T<Vec_T<lang::data::Node::Param_T>> params, Vec_T<lang::data::Node::Mod_T> mods, Vec_T<lang::data::Node::Field_T> fields) {
    auto ret1 = make_rc_ext<lang::data::Node::Decl::Data::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->name_ = name;
    ret1->base_ = base;
    ret1->params_ = params;
    ret1->mods_ = mods;
    ret1->fields_ = fields;
    return ret1;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_name(lang::data::Node::SumId_T name) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = name;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_base(Option_T<lang::data::Node::SumId_T> base) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = base;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_params(Option_T<Vec_T<lang::data::Node::Param_T>> params) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = params;
    ret->mods_ = this->mods_;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_mods(Vec_T<lang::data::Node::Mod_T> mods) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = mods;
    ret->fields_ = this->fields_;
    return ret;
}

lang::data::Node::Decl::Data_T lang::data::Node::Decl::Data::_T::with_fields(Vec_T<lang::data::Node::Field_T> fields) {
    auto ret = make_rc<lang::data::Node::Decl::Data::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->base_ = this->base_;
    ret->params_ = this->params_;
    ret->mods_ = this->mods_;
    ret->fields_ = fields;
    return ret;
}

void lang::data::Node::Decl::Data::_T::hash_ser_acc_lang_data_Node_Decl_Data(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Decl(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, name_);
    hash_ser(buf, base_);
    hash_ser(buf, params_);
    hash_ser(buf, mods_);
    hash_ser(buf, fields_);
}

void lang::data::Node::Decl::Data::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Decl::Data::_T::hash_ser_acc_lang_data_Node_Decl_Data(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Enum_T x) {
    os << "lang::data::Node::Decl::Enum {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "name: ";
    pr_debug(os, flags.sub_lo(), x->name_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "cases: ";
    pr_debug(os, flags.sub_lo(), x->cases_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Decl::Enum::_T::_T() : lang::data::Node::Decl::_T(lang::data::Node::Decl::_W::Enum) {
}

__attribute__((always_inline)) lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<StrSlice> cases) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->name_ = name;
    ret->cases_ = cases;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<StrSlice> cases) {
    auto ret1 = make_rc_ext<lang::data::Node::Decl::Enum::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->name_ = name;
    ret1->cases_ = cases;
    return ret1;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->name_ = this->name_;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_name(lang::data::Node::Id_T name) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = name;
    ret->cases_ = this->cases_;
    return ret;
}

lang::data::Node::Decl::Enum_T lang::data::Node::Decl::Enum::_T::with_cases(Vec_T<StrSlice> cases) {
    auto ret = make_rc<lang::data::Node::Decl::Enum::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->name_ = this->name_;
    ret->cases_ = cases;
    return ret;
}

void lang::data::Node::Decl::Enum::_T::hash_ser_acc_lang_data_Node_Decl_Enum(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Decl(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, name_);
    hash_ser(buf, cases_);
}

void lang::data::Node::Decl::Enum::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Decl::Enum::_T::hash_ser_acc_lang_data_Node_Decl_Enum(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Mut_T x) {
    os << "lang::data::Node::Mod::Mut {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Mod::Mut::_T::_T() : lang::data::Node::Mod::_T(lang::data::Node::Mod::_W::Mut) {
}

__attribute__((always_inline)) lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret1 = make_rc_ext<lang::data::Node::Mod::Mut::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    return ret1;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Mut_T lang::data::Node::Mod::Mut::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Mod::Mut::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    return ret;
}

void lang::data::Node::Mod::Mut::_T::hash_ser_acc_lang_data_Node_Mod_Mut(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Mod(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void lang::data::Node::Mod::Mut::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Mod::Mut::_T::hash_ser_acc_lang_data_Node_Mod_Mut(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Xform_T x) {
    os << "lang::data::Node::Mod::Xform {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Mod::Xform::_T::_T() : lang::data::Node::Mod::_T(lang::data::Node::Mod::_W::Xform) {
}

__attribute__((always_inline)) lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret1 = make_rc_ext<lang::data::Node::Mod::Xform::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    return ret1;
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Xform_T lang::data::Node::Mod::Xform::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Mod::Xform::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    return ret;
}

void lang::data::Node::Mod::Xform::_T::hash_ser_acc_lang_data_Node_Mod_Xform(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Mod(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void lang::data::Node::Mod::Xform::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Mod::Xform::_T::hash_ser_acc_lang_data_Node_Mod_Xform(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Visit_T x) {
    os << "lang::data::Node::Mod::Visit {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Mod::Visit::_T::_T() : lang::data::Node::Mod::_T(lang::data::Node::Mod::_W::Visit) {
}

__attribute__((always_inline)) lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret1 = make_rc_ext<lang::data::Node::Mod::Visit::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    return ret1;
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Mod::Visit_T lang::data::Node::Mod::Visit::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Mod::Visit::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    return ret;
}

void lang::data::Node::Mod::Visit::_T::hash_ser_acc_lang_data_Node_Mod_Visit(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Mod(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void lang::data::Node::Mod::Visit::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Mod::Visit::_T::hash_ser_acc_lang_data_Node_Mod_Visit(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::Id_T x) {
    os << "lang::data::Node::Expr::Id {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "ext: ";
    pr_debug(os, flags.sub_lo(), x->ext_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "x: ";
    pr_debug(os, flags.sub_lo(), x->x_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Expr::Id::_T::_T() : lang::data::Node::Expr::_T(lang::data::Node::Expr::_W::Id) {
}

__attribute__((always_inline)) lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool ext, lang::data::Node::Id_T x) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->ext_ = ext;
    ret->x_ = x;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool ext, lang::data::Node::Id_T x) {
    auto ret1 = make_rc_ext<lang::data::Node::Expr::Id::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->ext_ = ext;
    ret1->x_ = x;
    return ret1;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->ext_ = this->ext_;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->ext_ = this->ext_;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->ext_ = this->ext_;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->ext_ = this->ext_;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->ext_ = this->ext_;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->ext_ = this->ext_;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_ext(bool ext) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->ext_ = ext;
    ret->x_ = this->x_;
    return ret;
}

lang::data::Node::Expr::Id_T lang::data::Node::Expr::Id::_T::with_x(lang::data::Node::Id_T x) {
    auto ret = make_rc<lang::data::Node::Expr::Id::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->ext_ = this->ext_;
    ret->x_ = x;
    return ret;
}

void lang::data::Node::Expr::Id::_T::hash_ser_acc_lang_data_Node_Expr_Id(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Expr(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, ext_);
    hash_ser(buf, x_);
}

void lang::data::Node::Expr::Id::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Expr::Id::_T::hash_ser_acc_lang_data_Node_Expr_Id(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::App_T x) {
    os << "lang::data::Node::Expr::App {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "f: ";
    pr_debug(os, flags.sub_lo(), x->f_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "args: ";
    pr_debug(os, flags.sub_lo(), x->args_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Expr::App::_T::_T() : lang::data::Node::Expr::_T(lang::data::Node::Expr::_W::App) {
}

__attribute__((always_inline)) lang::data::Node::Expr::App_T lang::data::Node::Expr::App::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Expr_T f, Vec_T<lang::data::Node::Expr_T> args) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    ret->f_ = f;
    ret->args_ = args;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Expr::App_T lang::data::Node::Expr::App::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Expr_T f, Vec_T<lang::data::Node::Expr_T> args) {
    auto ret1 = make_rc_ext<lang::data::Node::Expr::App::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    ret1->f_ = f;
    ret1->args_ = args;
    return ret1;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->f_ = this->f_;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->f_ = this->f_;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->f_ = this->f_;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->f_ = this->f_;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    ret->f_ = this->f_;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    ret->f_ = this->f_;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_f(lang::data::Node::Expr_T f) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->f_ = f;
    ret->args_ = this->args_;
    return ret;
}

lang::data::Node::Expr::App_T lang::data::Node::Expr::App::_T::with_args(Vec_T<lang::data::Node::Expr_T> args) {
    auto ret = make_rc<lang::data::Node::Expr::App::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    ret->f_ = this->f_;
    ret->args_ = args;
    return ret;
}

void lang::data::Node::Expr::App::_T::hash_ser_acc_lang_data_Node_Expr_App(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Expr(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
    hash_ser(buf, f_);
    hash_ser(buf, args_);
}

void lang::data::Node::Expr::App::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Expr::App::_T::hash_ser_acc_lang_data_Node_Expr_App(buf);
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::Type__T x) {
    os << "lang::data::Node::Expr::Type_ {";
    flags.sub_lo().advance_lines(1, os);
    os << "id: ";
    pr_debug(os, flags.sub_lo(), x->id_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "bounds: ";
    pr_debug(os, flags.sub_lo(), x->bounds_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "is_top: ";
    pr_debug(os, flags.sub_lo(), x->is_top_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "sym: ";
    pr_debug(os, flags.sub_lo(), x->sym_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "attr: ";
    pr_debug(os, flags.sub_lo(), x->attr_);
    os << ",";
    flags.sub_lo().advance_lines(1, os);
    os << "first_k: ";
    pr_debug(os, flags.sub_lo(), x->first_k_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

lang::data::Node::Expr::Type_::_T::_T() : lang::data::Node::Expr::_T(lang::data::Node::Expr::_W::Type_) {
}

__attribute__((always_inline)) lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = id;
    ret->bounds_ = bounds;
    ret->is_top_ = is_top;
    ret->sym_ = sym;
    ret->attr_ = attr;
    ret->first_k_ = first_k;
    return ret;
}

__attribute__((always_inline)) lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k) {
    auto ret1 = make_rc_ext<lang::data::Node::Expr::Type_::_T>(arena);
    ret1->id_ = id;
    ret1->bounds_ = bounds;
    ret1->is_top_ = is_top;
    ret1->sym_ = sym;
    ret1->attr_ = attr;
    ret1->first_k_ = first_k;
    return ret1;
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::_T::with_id(Int id) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = id;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::_T::with_bounds(lang_rt::TokenBounds bounds) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = bounds;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::_T::with_is_top(bool is_top) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = is_top;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::_T::with_sym(lang_rt::ParserSymId sym) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = sym;
    ret->attr_ = this->attr_;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::_T::with_attr(lang_rt::ParserAttrMask attr) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = attr;
    ret->first_k_ = this->first_k_;
    return ret;
}

lang::data::Node::Expr::Type__T lang::data::Node::Expr::Type_::_T::with_first_k(lang_rt::ParserLookahead first_k) {
    auto ret = make_rc<lang::data::Node::Expr::Type_::_T>();
    ret->id_ = this->id_;
    ret->bounds_ = this->bounds_;
    ret->is_top_ = this->is_top_;
    ret->sym_ = this->sym_;
    ret->attr_ = this->attr_;
    ret->first_k_ = first_k;
    return ret;
}

void lang::data::Node::Expr::Type_::_T::hash_ser_acc_lang_data_Node_Expr_Type_(SerBuf& buf) const {
    this->hash_ser_acc_lang_data_Node_Expr(buf);
    hash_ser(buf, is_top_);
    hash_ser(buf, sym_);
    hash_ser(buf, attr_);
    hash_ser(buf, first_k_);
}

void lang::data::Node::Expr::Type_::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang::data::Node::Expr::Type_::_T::hash_ser_acc_lang_data_Node_Expr_Type_(buf);
}

void visit_lang_data_Node(lang::data::Node::Decl::Include_T x, function<void(lang::data::Node_T)> f) {
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Id_T x, function<void(lang::data::Node_T)> f) {
    Int i = 0;
    for (i = 0; i _LT_ x->items_->length(); i++) {
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Decl::Namespace_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->name_, f);
    Int i = 0;
    for (i = 0; i _LT_ x->body_->length(); i++) {
        visit_lang_data_Node(x->body_->at_unchecked(i), f);
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node::SumId_T x, function<void(lang::data::Node_T)> f) {
    Int i = 0;
    for (i = 0; i _LT_ x->items_->length(); i++) {
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Expr::Id_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->x_, f);
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Expr::App_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->f_, f);
    Int i = 0;
    for (i = 0; i _LT_ x->args_->length(); i++) {
        visit_lang_data_Node(x->args_->at_unchecked(i), f);
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Expr::Type__T x, function<void(lang::data::Node_T)> f) {
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Expr_T x, function<void(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::Expr::_W::Id: {
            visit_lang_data_Node(x->as_Id(), f);
            break;
        }
        case lang::data::Node::Expr::_W::App: {
            visit_lang_data_Node(x->as_App(), f);
            break;
        }
        case lang::data::Node::Expr::_W::Type_: {
            visit_lang_data_Node(x->as_Type_(), f);
            break;
        }
        default: {
            AX();
        }
    }
}

void visit_lang_data_Node(lang::data::Node::Param_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->type__, f);
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Mod::Mut_T x, function<void(lang::data::Node_T)> f) {
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Mod::Xform_T x, function<void(lang::data::Node_T)> f) {
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Mod::Visit_T x, function<void(lang::data::Node_T)> f) {
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Mod_T x, function<void(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::Mod::_W::Mut: {
            visit_lang_data_Node(x->as_Mut(), f);
            break;
        }
        case lang::data::Node::Mod::_W::Xform: {
            visit_lang_data_Node(x->as_Xform(), f);
            break;
        }
        case lang::data::Node::Mod::_W::Visit: {
            visit_lang_data_Node(x->as_Visit(), f);
            break;
        }
        default: {
            AX();
        }
    }
}

void visit_lang_data_Node(lang::data::Node::Field_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->type__, f);
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Decl::Data_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->name_, f);
    if (x->base_.is_some()) {
        visit_lang_data_Node(x->base_.as_some(), f);
    }
    if (x->params_.is_some()) {
        Int i = 0;
        for (i = 0; i _LT_ x->params_.as_some()->length(); i++) {
            visit_lang_data_Node(x->params_.as_some()->at_unchecked(i), f);
        }
    }
    Int i1 = 0;
    for (i1 = 0; i1 _LT_ x->mods_->length(); i1++) {
        visit_lang_data_Node(x->mods_->at_unchecked(i1), f);
    }
    Int i2 = 0;
    for (i2 = 0; i2 _LT_ x->fields_->length(); i2++) {
        visit_lang_data_Node(x->fields_->at_unchecked(i2), f);
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Decl::Enum_T x, function<void(lang::data::Node_T)> f) {
    visit_lang_data_Node(x->name_, f);
    Int i = 0;
    for (i = 0; i _LT_ x->cases_->length(); i++) {
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node::Decl_T x, function<void(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::Decl::_W::Include: {
            visit_lang_data_Node(x->as_Include(), f);
            break;
        }
        case lang::data::Node::Decl::_W::Namespace: {
            visit_lang_data_Node(x->as_Namespace(), f);
            break;
        }
        case lang::data::Node::Decl::_W::Data: {
            visit_lang_data_Node(x->as_Data(), f);
            break;
        }
        case lang::data::Node::Decl::_W::Enum: {
            visit_lang_data_Node(x->as_Enum(), f);
            break;
        }
        default: {
            AX();
        }
    }
}

void visit_lang_data_Node(lang::data::Node::Module_T x, function<void(lang::data::Node_T)> f) {
    Int i = 0;
    for (i = 0; i _LT_ x->decls_->length(); i++) {
        visit_lang_data_Node(x->decls_->at_unchecked(i), f);
    }
    f(x);
}

void visit_lang_data_Node(lang::data::Node_T x, function<void(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::_W::Module: {
            visit_lang_data_Node(x->as_Module(), f);
            break;
        }
        case lang::data::Node::_W::Param: {
            visit_lang_data_Node(x->as_Param(), f);
            break;
        }
        case lang::data::Node::_W::Field: {
            visit_lang_data_Node(x->as_Field(), f);
            break;
        }
        case lang::data::Node::_W::SumId: {
            visit_lang_data_Node(x->as_SumId(), f);
            break;
        }
        case lang::data::Node::_W::Id: {
            visit_lang_data_Node(x->as_Id(), f);
            break;
        }
        case lang::data::Node::_W::Decl: {
            visit_lang_data_Node(x->as_Decl(), f);
            break;
        }
        case lang::data::Node::_W::Mod: {
            visit_lang_data_Node(x->as_Mod(), f);
            break;
        }
        case lang::data::Node::_W::Expr: {
            visit_lang_data_Node(x->as_Expr(), f);
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Include_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Decl::Include_T z = lang::data::Node::Decl::Include::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, x->path_);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    auto ret = make_rc<Vec<StrSlice>>();
    Int i = 0;
    for (i = 0; i _LT_ x->items_->length(); i++) {
        ret->push_back(x->items_->at_unchecked(i));
    }
    lang::data::Node::Id_T z = lang::data::Node::Id::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, ret);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Namespace_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Id_T y = xform_lang_data_Node(x->name_, f);
    auto ret = make_rc<Vec<lang::data::Node::Decl_T>>();
    Int i = 0;
    for (i = 0; i _LT_ x->body_->length(); i++) {
        lang::data::Node::Decl_T y1 = xform_lang_data_Node(x->body_->at_unchecked(i), f);
        ret->push_back(y1);
    }
    lang::data::Node::Decl::Namespace_T z = lang::data::Node::Decl::Namespace::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, y, ret);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::SumId_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    auto ret = make_rc<Vec<StrSlice>>();
    Int i = 0;
    for (i = 0; i _LT_ x->items_->length(); i++) {
        ret->push_back(x->items_->at_unchecked(i));
    }
    lang::data::Node::SumId_T z = lang::data::Node::SumId::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, ret);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Id_T y = xform_lang_data_Node(x->x_, f);
    lang::data::Node::Expr::Id_T z = lang::data::Node::Expr::Id::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, x->ext_, y);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::App_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Expr_T y = xform_lang_data_Node(x->f_, f);
    auto ret = make_rc<Vec<lang::data::Node::Expr_T>>();
    Int i = 0;
    for (i = 0; i _LT_ x->args_->length(); i++) {
        lang::data::Node::Expr_T y1 = xform_lang_data_Node(x->args_->at_unchecked(i), f);
        ret->push_back(y1);
    }
    lang::data::Node::Expr::App_T z = lang::data::Node::Expr::App::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, y, ret);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::Type__T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Expr::Type__T z = lang::data::Node::Expr::Type_::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::Expr::_W::Id: {
            auto ret = xformT_lang_data_Node(x->as_Id(), f);
            return ret;
            break;
        }
        case lang::data::Node::Expr::_W::App: {
            auto ret1 = xformT_lang_data_Node(x->as_App(), f);
            return ret1;
            break;
        }
        case lang::data::Node::Expr::_W::Type_: {
            auto ret2 = xformT_lang_data_Node(x->as_Type_(), f);
            return ret2;
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Param_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Expr_T y = xform_lang_data_Node(x->type__, f);
    lang::data::Node::Param_T z = lang::data::Node::Param::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, x->name_, y);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Mut_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Mod::Mut_T z = lang::data::Node::Mod::Mut::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Xform_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Mod::Xform_T z = lang::data::Node::Mod::Xform::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Visit_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Mod::Visit_T z = lang::data::Node::Mod::Visit::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::Mod::_W::Mut: {
            auto ret = xformT_lang_data_Node(x->as_Mut(), f);
            return ret;
            break;
        }
        case lang::data::Node::Mod::_W::Xform: {
            auto ret1 = xformT_lang_data_Node(x->as_Xform(), f);
            return ret1;
            break;
        }
        case lang::data::Node::Mod::_W::Visit: {
            auto ret2 = xformT_lang_data_Node(x->as_Visit(), f);
            return ret2;
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Field_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Expr_T y = xform_lang_data_Node(x->type__, f);
    lang::data::Node::Field_T z = lang::data::Node::Field::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, x->name_, x->no_hash__, y);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Data_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::SumId_T y = xform_lang_data_Node(x->name_, f);
    auto ret = None<lang::data::Node::SumId_T>();
    if (x->base_.is_some()) {
        lang::data::Node::SumId_T y1 = xform_lang_data_Node(x->base_.as_some(), f);
        ret = Some<lang::data::Node::SumId_T>(y1);
    }
    auto ret1 = None<Vec_T<lang::data::Node::Param_T>>();
    if (x->params_.is_some()) {
        auto ret2 = make_rc<Vec<lang::data::Node::Param_T>>();
        Int i = 0;
        for (i = 0; i _LT_ x->params_.as_some()->length(); i++) {
            lang::data::Node::Param_T y2 = xform_lang_data_Node(x->params_.as_some()->at_unchecked(i), f);
            ret2->push_back(y2);
        }
        ret1 = Some<Vec_T<lang::data::Node::Param_T>>(ret2);
    }
    auto ret3 = make_rc<Vec<lang::data::Node::Mod_T>>();
    Int i1 = 0;
    for (i1 = 0; i1 _LT_ x->mods_->length(); i1++) {
        lang::data::Node::Mod_T y3 = xform_lang_data_Node(x->mods_->at_unchecked(i1), f);
        ret3->push_back(y3);
    }
    auto ret4 = make_rc<Vec<lang::data::Node::Field_T>>();
    Int i2 = 0;
    for (i2 = 0; i2 _LT_ x->fields_->length(); i2++) {
        lang::data::Node::Field_T y4 = xform_lang_data_Node(x->fields_->at_unchecked(i2), f);
        ret4->push_back(y4);
    }
    lang::data::Node::Decl::Data_T z = lang::data::Node::Decl::Data::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, y, ret, ret1, ret3, ret4);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Enum_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node::Id_T y = xform_lang_data_Node(x->name_, f);
    auto ret = make_rc<Vec<StrSlice>>();
    Int i = 0;
    for (i = 0; i _LT_ x->cases_->length(); i++) {
        ret->push_back(x->cases_->at_unchecked(i));
    }
    lang::data::Node::Decl::Enum_T z = lang::data::Node::Decl::Enum::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, y, ret);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::Decl::_W::Include: {
            auto ret = xformT_lang_data_Node(x->as_Include(), f);
            return ret;
            break;
        }
        case lang::data::Node::Decl::_W::Namespace: {
            auto ret1 = xformT_lang_data_Node(x->as_Namespace(), f);
            return ret1;
            break;
        }
        case lang::data::Node::Decl::_W::Data: {
            auto ret2 = xformT_lang_data_Node(x->as_Data(), f);
            return ret2;
            break;
        }
        case lang::data::Node::Decl::_W::Enum: {
            auto ret3 = xformT_lang_data_Node(x->as_Enum(), f);
            return ret3;
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Module_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    auto ret = make_rc<Vec<lang::data::Node::Decl_T>>();
    Int i = 0;
    for (i = 0; i _LT_ x->decls_->length(); i++) {
        lang::data::Node::Decl_T y = xform_lang_data_Node(x->decls_->at_unchecked(i), f);
        ret->push_back(y);
    }
    lang::data::Node::Module_T z = lang::data::Node::Module::make(x->id_, x->bounds_, x->is_top_, x->sym_, x->attr_, x->first_k_, ret);
    return f(z);
}

lang::data::Node_T xformT_lang_data_Node(lang::data::Node_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    switch (x->w_) {
        case lang::data::Node::_W::Module: {
            auto ret = xformT_lang_data_Node(x->as_Module(), f);
            return ret;
            break;
        }
        case lang::data::Node::_W::Param: {
            auto ret1 = xformT_lang_data_Node(x->as_Param(), f);
            return ret1;
            break;
        }
        case lang::data::Node::_W::Field: {
            auto ret2 = xformT_lang_data_Node(x->as_Field(), f);
            return ret2;
            break;
        }
        case lang::data::Node::_W::SumId: {
            auto ret3 = xformT_lang_data_Node(x->as_SumId(), f);
            return ret3;
            break;
        }
        case lang::data::Node::_W::Id: {
            auto ret4 = xformT_lang_data_Node(x->as_Id(), f);
            return ret4;
            break;
        }
        case lang::data::Node::_W::Decl: {
            auto ret5 = xformT_lang_data_Node(x->as_Decl(), f);
            return ret5;
            break;
        }
        case lang::data::Node::_W::Mod: {
            auto ret6 = xformT_lang_data_Node(x->as_Mod(), f);
            return ret6;
            break;
        }
        case lang::data::Node::_W::Expr: {
            auto ret7 = xformT_lang_data_Node(x->as_Expr(), f);
            return ret7;
            break;
        }
        default: {
            AX();
        }
    }
}

lang::data::Node_T xform_lang_data_Node(lang::data::Node_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret;
}

lang::data::Node::Module_T xform_lang_data_Node(lang::data::Node::Module_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Module();
}

lang::data::Node::Decl_T xform_lang_data_Node(lang::data::Node::Decl_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Decl();
}

lang::data::Node::Decl::Include_T xform_lang_data_Node(lang::data::Node::Decl::Include_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Decl()->as_Include();
}

lang::data::Node::Decl::Namespace_T xform_lang_data_Node(lang::data::Node::Decl::Namespace_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Decl()->as_Namespace();
}

lang::data::Node::Id_T xform_lang_data_Node(lang::data::Node::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Id();
}

lang::data::Node::Decl::Data_T xform_lang_data_Node(lang::data::Node::Decl::Data_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Decl()->as_Data();
}

lang::data::Node::SumId_T xform_lang_data_Node(lang::data::Node::SumId_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_SumId();
}

lang::data::Node::Param_T xform_lang_data_Node(lang::data::Node::Param_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Param();
}

lang::data::Node::Expr_T xform_lang_data_Node(lang::data::Node::Expr_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Expr();
}

lang::data::Node::Expr::Id_T xform_lang_data_Node(lang::data::Node::Expr::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Expr()->as_Id();
}

lang::data::Node::Expr::App_T xform_lang_data_Node(lang::data::Node::Expr::App_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Expr()->as_App();
}

lang::data::Node::Expr::Type__T xform_lang_data_Node(lang::data::Node::Expr::Type__T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Expr()->as_Type_();
}

lang::data::Node::Mod_T xform_lang_data_Node(lang::data::Node::Mod_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Mod();
}

lang::data::Node::Mod::Mut_T xform_lang_data_Node(lang::data::Node::Mod::Mut_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Mod()->as_Mut();
}

lang::data::Node::Mod::Xform_T xform_lang_data_Node(lang::data::Node::Mod::Xform_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Mod()->as_Xform();
}

lang::data::Node::Mod::Visit_T xform_lang_data_Node(lang::data::Node::Mod::Visit_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Mod()->as_Visit();
}

lang::data::Node::Field_T xform_lang_data_Node(lang::data::Node::Field_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Field();
}

lang::data::Node::Decl::Enum_T xform_lang_data_Node(lang::data::Node::Decl::Enum_T x, function<lang::data::Node_T(lang::data::Node_T)> f) {
    lang::data::Node_T ret = xformT_lang_data_Node(x, f);
    return ret->as_Decl()->as_Enum();
}

void lang::data::Node::Module::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Module::_T>();
    {
        Int i;
        bool is_iter = false;
        bool indented = false;
        for (i = 0; i _LT_ len(x->decls_); i++) {
            auto xi = x->decls_->at_unchecked(i);
            if (is_iter) {
                pb->push_string("");
                pb->push_newlines(2);
            }
            if (!is_iter) {
                indented = true;
            }
            is_iter = true;
            xi->write(pb);
        }
        pb->push_newlines(1);
    }
}

void lang::data::Node::Module::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Decl::Include::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Decl::Include::_T>();
    pb->push_string("#include");
    pb->push_string(" ");
    pb->push_string(fmt_str("{}", x->path_));
}

void lang::data::Node::Decl::Include::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Decl::Namespace::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Decl::Namespace::_T>();
    pb->push_string("namespace");
    pb->push_string(" ");
    x->name_->write(pb);
    pb->push_string(" ");
    pb->push_string("{");
    {
        Int i;
        bool is_iter = false;
        bool indented = false;
        for (i = 0; i _LT_ len(x->body_); i++) {
            auto xi = x->body_->at_unchecked(i);
            if (is_iter) {
                pb->push_string("");
                pb->push_newlines(2);
            }
            if (!is_iter) {
                pb->push_newlines(1);
                pb->push_indent();
                indented = true;
            }
            is_iter = true;
            xi->write(pb);
        }
        pb->push_newlines(1);
        if (indented) {
            pb->push_dedent();
        }
    }
    pb->push_string("}");
}

void lang::data::Node::Decl::Namespace::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Decl::Data::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Decl::Data::_T>();
    pb->push_string("def");
    pb->push_string(" ");
    x->name_->write(pb);
    if (x->base_.is_some()) {
        pb->push_string(" ");
        pb->push_string("<:");
        pb->push_string(" ");
        x->base_.as_some()->write(pb);
    }
    if (x->params_.is_some()) {
        pb->push_string("(");
        {
            Int i;
            bool is_iter = false;
            bool indented = false;
            for (i = 0; i _LT_ len(x->params_.as_some()); i++) {
                auto xi = x->params_.as_some()->at_unchecked(i);
                if (is_iter) {
                    pb->push_string(", ");
                }
                if (!is_iter) {
                    indented = true;
                }
                is_iter = true;
                xi->write(pb);
            }
        }
        pb->push_string(")");
    }
    pb->push_string(" ");
    {
        Int i1;
        bool is_iter1 = false;
        bool indented1 = false;
        for (i1 = 0; i1 _LT_ len(x->mods_); i1++) {
            auto xi1 = x->mods_->at_unchecked(i1);
            if (is_iter1) {
                pb->push_string(" ");
            }
            if (!is_iter1) {
                indented1 = true;
            }
            is_iter1 = true;
            xi1->write(pb);
        }
        if (is_iter1) {
            pb->push_string(" ");
        }
    }
    pb->push_string("{");
    {
        Int i2;
        bool is_iter2 = false;
        bool indented2 = false;
        for (i2 = 0; i2 _LT_ len(x->fields_); i2++) {
            auto xi2 = x->fields_->at_unchecked(i2);
            if (is_iter2) {
                pb->push_string("");
                pb->push_newlines(1);
            }
            if (!is_iter2) {
                pb->push_newlines(1);
                pb->push_indent();
                indented2 = true;
            }
            is_iter2 = true;
            xi2->write(pb);
        }
        pb->push_newlines(1);
        if (indented2) {
            pb->push_dedent();
        }
    }
    pb->push_string("}");
}

void lang::data::Node::Decl::Data::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Decl::Enum::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Decl::Enum::_T>();
    pb->push_string("enum");
    pb->push_string(" ");
    x->name_->write(pb);
    pb->push_string("{");
    {
        Int i;
        bool is_iter = false;
        bool indented = false;
        for (i = 0; i _LT_ len(x->cases_); i++) {
            auto xi = x->cases_->at_unchecked(i);
            if (is_iter) {
                pb->push_string(";");
                pb->push_newlines(1);
            }
            if (!is_iter) {
                pb->push_newlines(1);
                pb->push_indent();
                indented = true;
            }
            is_iter = true;
            pb->push_string(fmt_str("{}", xi));
        }
        if (is_iter) {
            pb->push_string(";");
        }
        pb->push_newlines(1);
        if (indented) {
            pb->push_dedent();
        }
    }
    pb->push_string("}");
}

void lang::data::Node::Decl::Enum::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Mod::Mut::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Mod::Mut::_T>();
    pb->push_string("mut");
}

void lang::data::Node::Mod::Mut::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Mod::Xform::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Mod::Xform::_T>();
    pb->push_string("xform");
}

void lang::data::Node::Mod::Xform::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Mod::Visit::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Mod::Visit::_T>();
    pb->push_string("visit");
}

void lang::data::Node::Mod::Visit::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Param::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Param::_T>();
    pb->push_string(fmt_str("{}", x->name_));
    pb->push_string(":");
    pb->push_string(" ");
    x->type__->write(pb);
}

void lang::data::Node::Param::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Field::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Field::_T>();
    pb->push_string(fmt_str("{}", x->name_));
    if (x->no_hash__) {
        pb->push_string(" ");
        pb->push_string("no_hash");
    }
    pb->push_string(":");
    pb->push_string(" ");
    x->type__->write(pb);
    pb->push_string(";");
}

void lang::data::Node::Field::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Expr::Id::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Expr::Id::_T>();
    if (x->ext_) {
        pb->push_string("^");
    }
    x->x_->write(pb);
}

void lang::data::Node::Expr::Id::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Expr::App::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Expr::App::_T>();
    x->f_->write(pb);
    pb->push_string("(");
    {
        Int i;
        bool is_iter = false;
        bool indented = false;
        for (i = 0; i _LT_ len(x->args_); i++) {
            auto xi = x->args_->at_unchecked(i);
            if (is_iter) {
                pb->push_string(", ");
            }
            if (!is_iter) {
                indented = true;
            }
            is_iter = true;
            xi->write(pb);
        }
    }
    pb->push_string(")");
}

void lang::data::Node::Expr::App::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Expr::Type_::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Expr::Type_::_T>();
    pb->push_string("Type");
}

void lang::data::Node::Expr::Type_::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::SumId::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::SumId::_T>();
    {
        Int i;
        bool is_iter = false;
        bool indented = false;
        for (i = 0; i _LT_ len(x->items_); i++) {
            auto xi = x->items_->at_unchecked(i);
            if (is_iter) {
                pb->push_string(".");
            }
            if (!is_iter) {
                indented = true;
            }
            is_iter = true;
            pb->push_string(fmt_str("{}", xi));
        }
    }
}

void lang::data::Node::SumId::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Id::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Id::_T>();
    {
        Int i;
        bool is_iter = false;
        bool indented = false;
        for (i = 0; i _LT_ len(x->items_); i++) {
            auto xi = x->items_->at_unchecked(i);
            if (is_iter) {
                pb->push_string("::");
            }
            if (!is_iter) {
                indented = true;
            }
            is_iter = true;
            pb->push_string(fmt_str("{}", xi));
        }
    }
}

void lang::data::Node::Id::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Decl::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Decl::_T>();
    switch (x->w_) {
        case lang::data::Node::Decl::_W::Include: {
            x->as_Include()->write(pb);
            break;
        }
        case lang::data::Node::Decl::_W::Namespace: {
            x->as_Namespace()->write(pb);
            break;
        }
        case lang::data::Node::Decl::_W::Data: {
            x->as_Data()->write(pb);
            break;
        }
        case lang::data::Node::Decl::_W::Enum: {
            x->as_Enum()->write(pb);
            break;
        }
        default: {
            AX();
        }
    }
}

void lang::data::Node::Decl::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Mod::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Mod::_T>();
    switch (x->w_) {
        case lang::data::Node::Mod::_W::Mut: {
            x->as_Mut()->write(pb);
            break;
        }
        case lang::data::Node::Mod::_W::Xform: {
            x->as_Xform()->write(pb);
            break;
        }
        case lang::data::Node::Mod::_W::Visit: {
            x->as_Visit()->write(pb);
            break;
        }
        default: {
            AX();
        }
    }
}

void lang::data::Node::Mod::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::Expr::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::Expr::_T>();
    switch (x->w_) {
        case lang::data::Node::Expr::_W::Id: {
            x->as_Id()->write(pb);
            break;
        }
        case lang::data::Node::Expr::_W::App: {
            x->as_App()->write(pb);
            break;
        }
        case lang::data::Node::Expr::_W::Type_: {
            x->as_Type_()->write(pb);
            break;
        }
        default: {
            AX();
        }
    }
}

void lang::data::Node::Expr::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

void lang::data::Node::_T::write(lang_rt::PrBufStream_T& pb) {
    auto x = this->rc_from_this_poly<lang::data::Node::_T>();
    switch (x->w_) {
        case lang::data::Node::_W::Module: {
            x->as_Module()->write(pb);
            break;
        }
        case lang::data::Node::_W::Decl: {
            x->as_Decl()->write(pb);
            break;
        }
        case lang::data::Node::_W::Mod: {
            x->as_Mod()->write(pb);
            break;
        }
        case lang::data::Node::_W::Param: {
            x->as_Param()->write(pb);
            break;
        }
        case lang::data::Node::_W::Field: {
            x->as_Field()->write(pb);
            break;
        }
        case lang::data::Node::_W::Expr: {
            x->as_Expr()->write(pb);
            break;
        }
        case lang::data::Node::_W::SumId: {
            x->as_SumId()->write(pb);
            break;
        }
        case lang::data::Node::_W::Id: {
            x->as_Id()->write(pb);
            break;
        }
        default: {
            AX();
        }
    }
}

void lang::data::Node::_T::write(ostream& os, FmtFlags flags) {
    auto pb = lang_rt::PrBufStream::make(make_rc<Vec<lang_rt::PrBufStreamItem_T>>());
    this->write(pb);
    pb->distill(os, flags);
}

__attribute__((always_inline)) IntPair lang::data::parser::action_by_vertex(lang_rt::ParserVertexId v, lang_rt::ParserLookahead la) {
    static const u16_array tt_acc_raw = {0x0304, 0x0402, 0x0404, 0x0404, 0x0101, 0x0401, 0x0401, 0x0401, 0x0401, 0x0401, 0x0103, 0x0101, 0x0403, 0x0404, 0x0304, 0x0304, 0x0104, 0x0304, 0x0101, 0x0301, 0x0101, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0202, 0x0202, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0202, 0x0302, 0x0404, 0x0402, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0402, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0102, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0402, 0x0404, 0x0404, 0x0204, 0x0401, 0x0404, 0x0404, 0x0402, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0104, 0x0304, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0101, 0x0301, 0x0101, 0x0401, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0104, 0x0401, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0103, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0403, 0x0404, 0x0304, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0104, 0x0401, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0401, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0104, 0x0401, 0x0104, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0304, 0x0101, 0x0301, 0x0101, 0x0401, 0x0404, 0x0401, 0x0404, 0x0404, 0x0401, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0104, 0x0304, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0401, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0401, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0404, 0x0404, 0x0104, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0104, 0x0304, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0102, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0202, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0403, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0202, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0403, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0202, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0403, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0102, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0101, 0x0401, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0204, 0x0401, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0103, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0101, 0x0401, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0204, 0x0401, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0103, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0304, 0x0101, 0x0401, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0101, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0204, 0x0401, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0103, 0x0101, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0202, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0403, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0204, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0402, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0401, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0104, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404, 0x0404};
    static const u16_array tt_arg = {0x0000, 0x0001, 0x001e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000f, 0x0015, 0x0010, 0x0000, 0x0011, 0x0000, 0x0012, 0x0000, 0x0013, 0x0000, 0x0014, 0x0000, 0x001e, 0x0000, 0x0016, 0x0018, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0022, 0x0000, 0x0023, 0x0000, 0x000c, 0x0000, 0x0025, 0x000e, 0x0041, 0x0043, 0x0024, 0x000d, 0x003e, 0x0040, 0x0017, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0042, 0x003f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000b, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0000, 0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0022, 0x0023, 0x0025, 0x0024, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0025, 0x0024, 0x0025, 0x0022, 0x0000, 0x0000, 0x0025, 0x0000, 0x0037, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0024, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x003d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0009, 0x0000, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0027, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0022, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0035, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0034, 0x0036, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x000c, 0x0000, 0x0025, 0x000e, 0x0041, 0x0043, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0042, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0025, 0x000e, 0x0041, 0x0043, 0x0024, 0x000d, 0x003e, 0x0040, 0x0000, 0x0000, 0x0000, 0x001e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x001d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0042, 0x003f, 0x0000, 0x0000, 0x0000, 0x0028, 0x0020, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0029, 0x002b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x002a, 0x0020, 0x0005, 0x0006, 0x0007, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0019, 0x0000, 0x0000, 0x0000, 0x0030, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001a, 0x001c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0031, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x001b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0033, 0x0009, 0x0000, 0x002c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0032, 0x0000, 0x002d, 0x002f, 0x0000, 0x0000, 0x0003, 0x002e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000c, 0x0000, 0x0025, 0x000e, 0x0041, 0x0043, 0x0024, 0x000d, 0x003e, 0x0040, 0x0000, 0x0000, 0x0000, 0x001e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x001d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0042, 0x003f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x000b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x000c, 0x0000, 0x0025, 0x000e, 0x0041, 0x0043, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0039, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003a, 0x003c, 0x0042, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0024, 0x0026, 0x0000, 0x0000, 0x0000, 0x0000, 0x003b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0025, 0x0000, 0x0000, 0x0000, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x000c, 0x0000, 0x0025, 0x000e, 0x0041, 0x0043, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0042, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x003d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0024, 0x000d, 0x003e, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001e, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x001e, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x001e, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x003d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0024, 0x000d, 0x003e, 0x0040, 0x0000, 0x0000, 0x0000, 0x001e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x001d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003f, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0005, 0x0006, 0x0007, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0024, 0x000d, 0x003e, 0x0040, 0x0000, 0x0000, 0x0000, 0x001e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x001d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003f, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0005, 0x0006, 0x0007, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0024, 0x000d, 0x003e, 0x0040, 0x0000, 0x0000, 0x0000, 0x001e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x001d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003f, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0005, 0x0006, 0x0007, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001e, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
    auto tt_acc = lang_rt::table_u16_array_as_u8_array(tt_acc_raw);
    Int ind = la.v_[0] * 114 + v;
    Int ret_acc = tt_acc[ind];
    Int ret_arg = tt_arg[ind];
    return make_pair(ret_acc, ret_arg);
}

__attribute__((always_inline)) lang_rt::ParserVertexId lang::data::parser::vertex_dfa_step(lang_rt::ParserVertexId v, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr) {
    static const u16_array tt = {0x0002, 0x0000, 0x0072, 0x00e4, 0x0000, 0x0106, 0x0000, 0x010c, 0x0000, 0x011a, 0x0000, 0x0128, 0x0000, 0x0136, 0x0000, 0x0144, 0x0000, 0x0152, 0x0000, 0x0160, 0x0000, 0x0166, 0x0000, 0x0180, 0x0000, 0x0186, 0x0000, 0x01a0, 0x0000, 0x01a6, 0x0000, 0x01b4, 0x0000, 0x01ba, 0x0000, 0x01d0, 0x0000, 0x01d6, 0x0000, 0x01ec, 0x0000, 0x01f2, 0x0000, 0x0208, 0x0000, 0x020e, 0x0000, 0x0214, 0x0000, 0x021a, 0x0000, 0x022c, 0x0000, 0x0232, 0x0000, 0x023c, 0x0000, 0x024a, 0x0000, 0x0258, 0x0000, 0x0266, 0x0000, 0x026c, 0x0000, 0x027e, 0x0000, 0x0288, 0x0000, 0x0296, 0x0000, 0x029c, 0x0000, 0x02a2, 0x0000, 0x02a8, 0x0000, 0x02ae, 0x0000, 0x02b4, 0x0000, 0x02be, 0x0000, 0x02c4, 0x0000, 0x02ca, 0x0000, 0x02d0, 0x0000, 0x02da, 0x0000, 0x02e0, 0x0000, 0x02e6, 0x0000, 0x02f0, 0x0000, 0x0302, 0x0000, 0x030c, 0x0000, 0x0316, 0x0000, 0x031c, 0x0000, 0x0322, 0x0000, 0x0338, 0x0000, 0x033e, 0x0000, 0x034c, 0x0000, 0x035a, 0x0000, 0x0370, 0x0000, 0x0382, 0x0000, 0x0388, 0x0000, 0x0396, 0x0000, 0x03a8, 0x0000, 0x03b6, 0x0000, 0x03c0, 0x0000, 0x03c6, 0x0000, 0x03d4, 0x0000, 0x03da, 0x0000, 0x03e0, 0x0000, 0x03ea, 0x0000, 0x03f0, 0x0000, 0x0402, 0x0000, 0x0418, 0x0000, 0x041e, 0x0000, 0x0434, 0x0000, 0x043a, 0x0000, 0x0444, 0x0000, 0x044a, 0x0000, 0x0454, 0x0000, 0x045e, 0x0000, 0x0464, 0x0000, 0x0476, 0x0000, 0x047c, 0x0000, 0x0482, 0x0000, 0x0488, 0x0000, 0x0492, 0x0000, 0x0498, 0x0000, 0x04aa, 0x0000, 0x04c0, 0x0000, 0x04ca, 0x0000, 0x04d0, 0x0000, 0x04de, 0x0000, 0x04ec, 0x0000, 0x04f2, 0x0000, 0x0500, 0x0000, 0x0506, 0x0000, 0x050c, 0x0000, 0x0522, 0x0000, 0x0528, 0x0000, 0x052e, 0x0000, 0x0534, 0x0000, 0x053a, 0x0000, 0x0540, 0x0000, 0x0546, 0x0000, 0x0558, 0x0000, 0x055e, 0x0000, 0x0564, 0x0000, 0x056e, 0x0000, 0x0574, 0x0000, 0x057e, 0x0000, 0x0584, 0x0000, 0x0596, 0x0000, 0x059c, 0x0000, 0x05aa, 0x0000, 0x05b0, 0x0000, 0x05b6, 0x0000, 0x0001, 0x0001, 0x0007, 0x0001, 0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x000f, 0x0011, 0x0013, 0x0015, 0x0017, 0x0019, 0x001b, 0x001d, 0x0000, 0x0001, 0x0000, 0x0002, 0x0000, 0x0003, 0x0000, 0x0004, 0x0000, 0x0005, 0x0000, 0x0006, 0x0000, 0x0007, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x001e, 0x0041, 0x0005, 0x0007, 0x0009, 0x0000, 0x0008, 0x0000, 0x0009, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x001f, 0x0042, 0x0005, 0x0007, 0x0009, 0x0000, 0x000a, 0x0000, 0x000b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0022, 0x0045, 0x0005, 0x0007, 0x0009, 0x0000, 0x000c, 0x0000, 0x000d, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0023, 0x0046, 0x0005, 0x0007, 0x0009, 0x0000, 0x000e, 0x0000, 0x000f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0025, 0x0048, 0x0005, 0x0007, 0x0009, 0x0000, 0x0010, 0x0000, 0x0011, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0024, 0x0047, 0x0005, 0x0007, 0x0009, 0x0000, 0x0012, 0x0000, 0x0013, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0005, 0x001e, 0x0026, 0x0027, 0x001f, 0x0042, 0x000b, 0x000d, 0x000f, 0x0011, 0x0013, 0x0015, 0x0000, 0x0014, 0x0000, 0x0015, 0x0000, 0x0016, 0x0000, 0x0017, 0x0000, 0x000b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0005, 0x001f, 0x0015, 0x0010, 0x000e, 0x000f, 0x000b, 0x000d, 0x000f, 0x0011, 0x0013, 0x0015, 0x0000, 0x0018, 0x0000, 0x0019, 0x0000, 0x001a, 0x0000, 0x001b, 0x0000, 0x001c, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0022, 0x0002, 0x0005, 0x0007, 0x0009, 0x0000, 0x001d, 0x0000, 0x001e, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0023, 0x0039, 0x0011, 0x000c, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x001f, 0x0000, 0x0020, 0x0000, 0x0021, 0x0000, 0x0022, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0025, 0x003f, 0x0040, 0x0002, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x0023, 0x0000, 0x0024, 0x0000, 0x0025, 0x0000, 0x0026, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0024, 0x003d, 0x003e, 0x0002, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x0027, 0x0000, 0x0028, 0x0000, 0x0029, 0x0000, 0x002a, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x0027, 0x001f, 0x0042, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x002b, 0x0000, 0x0017, 0x0000, 0x000b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0017, 0x0003, 0x0005, 0x0000, 0x002c, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0025, 0x0048, 0x0005, 0x0007, 0x0009, 0x0000, 0x002d, 0x0000, 0x0011, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0024, 0x0047, 0x0005, 0x0007, 0x0009, 0x0000, 0x002e, 0x0000, 0x0013, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0025, 0x0048, 0x0005, 0x0007, 0x0009, 0x0000, 0x002f, 0x0000, 0x0011, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x0037, 0x0038, 0x0016, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x0030, 0x0000, 0x0031, 0x0000, 0x0032, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0009, 0x0003, 0x0005, 0x0000, 0x0033, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0025, 0x0048, 0x0005, 0x0007, 0x0009, 0x0000, 0x0034, 0x0000, 0x0011, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0006, 0x0003, 0x0005, 0x0000, 0x0035, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0003, 0x0003, 0x0005, 0x0000, 0x0036, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0007, 0x0003, 0x0005, 0x0000, 0x0037, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x002a, 0x002b, 0x000d, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x0038, 0x0000, 0x0039, 0x0000, 0x003a, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0007, 0x0003, 0x0005, 0x0000, 0x003b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0004, 0x0003, 0x0005, 0x0000, 0x003c, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x003a, 0x003b, 0x0023, 0x0046, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x003d, 0x0000, 0x003e, 0x0000, 0x003f, 0x0000, 0x000f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0040, 0x0002, 0x0005, 0x0007, 0x0009, 0x0000, 0x0040, 0x0000, 0x0026, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x003e, 0x0002, 0x0005, 0x0007, 0x0009, 0x0000, 0x0041, 0x0000, 0x002a, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0028, 0x0029, 0x001f, 0x0042, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x0042, 0x0000, 0x0043, 0x0000, 0x0044, 0x0000, 0x000b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x002c, 0x002d, 0x0009, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x0045, 0x0000, 0x0046, 0x0000, 0x0047, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0024, 0x0047, 0x0005, 0x0007, 0x0009, 0x0000, 0x0048, 0x0000, 0x0013, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x0035, 0x0036, 0x0002, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x0049, 0x0000, 0x004a, 0x0000, 0x004b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0023, 0x0046, 0x0005, 0x0007, 0x0009, 0x0000, 0x004c, 0x0000, 0x000f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x000a, 0x0003, 0x0005, 0x0000, 0x004d, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x003c, 0x000b, 0x0005, 0x0007, 0x0009, 0x0000, 0x004e, 0x0000, 0x004f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0008, 0x0003, 0x0005, 0x0000, 0x0050, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x0029, 0x001f, 0x0042, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x0051, 0x0000, 0x0044, 0x0000, 0x000b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0031, 0x0032, 0x0020, 0x0043, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x0052, 0x0000, 0x0053, 0x0000, 0x0054, 0x0000, 0x0055, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x002e, 0x002f, 0x0021, 0x0044, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x0056, 0x0000, 0x0057, 0x0000, 0x0058, 0x0000, 0x0059, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0008, 0x0003, 0x0005, 0x0000, 0x005a, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0005, 0x0003, 0x0005, 0x0000, 0x005b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0005, 0x0003, 0x0005, 0x0000, 0x005c, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x003b, 0x0023, 0x0046, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x005d, 0x0000, 0x003f, 0x0000, 0x000f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0007, 0x0003, 0x0005, 0x0000, 0x005e, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x0032, 0x0020, 0x0043, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x005f, 0x0000, 0x0054, 0x0000, 0x0055, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0020, 0x0012, 0x0013, 0x0014, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x0060, 0x0000, 0x0061, 0x0000, 0x0062, 0x0000, 0x0063, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x000a, 0x0003, 0x0005, 0x0000, 0x0064, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0030, 0x000b, 0x0005, 0x0007, 0x0009, 0x0000, 0x0065, 0x0000, 0x0066, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0021, 0x0002, 0x0005, 0x0007, 0x0009, 0x0000, 0x0067, 0x0000, 0x0068, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0036, 0x0002, 0x0005, 0x0007, 0x0009, 0x0000, 0x0069, 0x0000, 0x004b, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0004, 0x0033, 0x0034, 0x0022, 0x0045, 0x0009, 0x000b, 0x000d, 0x000f, 0x0011, 0x0000, 0x006a, 0x0000, 0x006b, 0x0000, 0x006c, 0x0000, 0x000d, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x002f, 0x0021, 0x0044, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x006d, 0x0000, 0x0058, 0x0000, 0x0059, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0004, 0x0003, 0x0005, 0x0000, 0x006e, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0001, 0x0008, 0x0003, 0x0005, 0x0000, 0x006f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0003, 0x0034, 0x0022, 0x0045, 0x0007, 0x0009, 0x000b, 0x000d, 0x0000, 0x0070, 0x0000, 0x006c, 0x0000, 0x000d, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0002, 0x0023, 0x0046, 0x0005, 0x0007, 0x0009, 0x0000, 0x0071, 0x0000, 0x000f, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0xffff};
    return lang_rt::table_decode_r2_vec<i16, u16>(tt, v, sym, attr);
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_0_4_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto x = rc_from_ptr_ext<Vec<rc_ptr<lang::data::Node::Decl::_T>>>(reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Decl::_T>>>>(res0.v_), st->unw_arena_);
        x.decref();
        auto ret = lang::data::Node::Module::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {30, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_1_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto x_site = lang_rt::result_decode_token_bounds(res0);
        auto x = st->fetch_token(x_site.lo_);
        auto ret = lang::data::Node::Decl::Include::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {31, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_2_4_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 5;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        auto sym3 = st->Ss_addr_[ss_len - 4];
        auto sym4 = st->Ss_addr_[ss_len - 5];
        ss_len = ss_len - 5;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        auto res3 = st->Sr_addr_[sr_len - 4];
        auto res4 = st->Sr_addr_[sr_len - 5];
        sr_len = sr_len - 5;
        auto x = reinterpret_cast<ptr<lang::data::Node::Id::_T>>(res3.v_)->rc_from_this_poly<lang::data::Node::Id::_T>();
        x.decref();
        auto x1 = rc_from_ptr_ext<Vec<rc_ptr<lang::data::Node::Decl::_T>>>(reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Decl::_T>>>>(res1.v_), st->unw_arena_);
        x1.decref();
        auto ret = lang::data::Node::Decl::Namespace::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {31, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_19_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 8;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        auto sym3 = st->Ss_addr_[ss_len - 4];
        auto sym4 = st->Ss_addr_[ss_len - 5];
        auto sym5 = st->Ss_addr_[ss_len - 6];
        auto sym6 = st->Ss_addr_[ss_len - 7];
        auto sym7 = st->Ss_addr_[ss_len - 8];
        ss_len = ss_len - 8;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        auto res3 = st->Sr_addr_[sr_len - 4];
        auto res4 = st->Sr_addr_[sr_len - 5];
        auto res5 = st->Sr_addr_[sr_len - 6];
        auto res6 = st->Sr_addr_[sr_len - 7];
        auto res7 = st->Sr_addr_[sr_len - 8];
        sr_len = sr_len - 8;
        auto x = reinterpret_cast<ptr<lang::data::Node::SumId::_T>>(res6.v_)->rc_from_this_poly<lang::data::Node::SumId::_T>();
        x.decref();
        auto x1 = rc_from_ptr_ext_take<Option_T<rc_ptr<lang::data::Node::SumId::_T>>>(reinterpret_cast<ptr<Option_T<rc_ptr<lang::data::Node::SumId::_T>>>>(res5.v_), st->unw_arena_);
        auto x2 = rc_from_ptr_ext_take<Option_T<Vec_T<rc_ptr<lang::data::Node::Param::_T>>>>(reinterpret_cast<ptr<Option_T<Vec_T<rc_ptr<lang::data::Node::Param::_T>>>>>(res4.v_), st->unw_arena_);
        auto x3 = rc_from_ptr_ext<Vec<rc_ptr<lang::data::Node::Mod::_T>>>(reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Mod::_T>>>>(res3.v_), st->unw_arena_);
        x3.decref();
        auto x4 = rc_from_ptr_ext<Vec<rc_ptr<lang::data::Node::Field::_T>>>(reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Field::_T>>>>(res1.v_), st->unw_arena_);
        x4.decref();
        auto ret = lang::data::Node::Decl::Data::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1, x2, x3, x4);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {31, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_4_4_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 5;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        auto sym3 = st->Ss_addr_[ss_len - 4];
        auto sym4 = st->Ss_addr_[ss_len - 5];
        ss_len = ss_len - 5;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        auto res3 = st->Sr_addr_[sr_len - 4];
        auto res4 = st->Sr_addr_[sr_len - 5];
        sr_len = sr_len - 5;
        auto x = reinterpret_cast<ptr<lang::data::Node::Id::_T>>(res3.v_)->rc_from_this_poly<lang::data::Node::Id::_T>();
        x.decref();
        auto x1 = rc_from_ptr_ext<Vec<StrSlice>>(reinterpret_cast<ptr<Vec<StrSlice>>>(res1.v_), st->unw_arena_);
        x1.decref();
        auto ret = lang::data::Node::Decl::Enum::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {31, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_5_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto ret = lang::data::Node::Mod::Mut::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead());
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {32, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_6_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto ret = lang::data::Node::Mod::Xform::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead());
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {32, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_7_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto ret = lang::data::Node::Mod::Visit::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead());
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {32, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_8_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        auto x_site = lang_rt::result_decode_token_bounds(res2);
        auto x = st->fetch_token(x_site.lo_);
        auto x1 = reinterpret_cast<ptr<lang::data::Node::Expr::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Expr::_T>();
        x1.decref();
        auto ret = lang::data::Node::Param::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {33, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_9_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 5;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        auto sym3 = st->Ss_addr_[ss_len - 4];
        auto sym4 = st->Ss_addr_[ss_len - 5];
        ss_len = ss_len - 5;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        auto res3 = st->Sr_addr_[sr_len - 4];
        auto res4 = st->Sr_addr_[sr_len - 5];
        sr_len = sr_len - 5;
        auto x_site = lang_rt::result_decode_token_bounds(res4);
        auto x = st->fetch_token(x_site.lo_);
        auto x1 = rc_from_ptr_ext_take<bool>(reinterpret_cast<ptr<bool>>(res3.v_), st->unw_arena_);
        auto x2 = reinterpret_cast<ptr<lang::data::Node::Expr::_T>>(res1.v_)->rc_from_this_poly<lang::data::Node::Expr::_T>();
        x2.decref();
        auto ret = lang::data::Node::Field::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1, x2);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {34, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_10_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto x = rc_from_ptr_ext_take<bool>(reinterpret_cast<ptr<bool>>(res1.v_), st->unw_arena_);
        auto x1 = reinterpret_cast<ptr<lang::data::Node::Id::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Id::_T>();
        x1.decref();
        auto ret = lang::data::Node::Expr::Id::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {35, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_11_5_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 4;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        auto sym3 = st->Ss_addr_[ss_len - 4];
        ss_len = ss_len - 4;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        auto res3 = st->Sr_addr_[sr_len - 4];
        sr_len = sr_len - 4;
        auto x = reinterpret_cast<ptr<lang::data::Node::Expr::_T>>(res3.v_)->rc_from_this_poly<lang::data::Node::Expr::_T>();
        x.decref();
        auto x1 = rc_from_ptr_ext<Vec<rc_ptr<lang::data::Node::Expr::_T>>>(reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Expr::_T>>>>(res1.v_), st->unw_arena_);
        x1.decref();
        auto ret = lang::data::Node::Expr::App::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x, x1);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {35, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_12_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto ret = lang::data::Node::Expr::Type_::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead());
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {35, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_13_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto x = rc_from_ptr_ext<Vec<StrSlice>>(reinterpret_cast<ptr<Vec<StrSlice>>>(res0.v_), st->unw_arena_);
        x.decref();
        auto ret = lang::data::Node::SumId::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {36, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_14_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto x = rc_from_ptr_ext<Vec<StrSlice>>(reinterpret_cast<ptr<Vec<StrSlice>>>(res0.v_), st->unw_arena_);
        x.decref();
        auto ret = lang::data::Node::Id::make_ext(st->unw_arena_, st->gen()->gen(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_), false, -1, lang_rt::ParserAttrMask(), lang_rt::ParserLookahead(), x);
        ret.incref();
        auto res_item = lang_rt::Result_T(ret.get(), lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {37, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_start_30_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->enroll_final_sym(sym0);
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {1, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_start_31_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->enroll_final_sym(sym0);
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {1, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_start_34_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->enroll_final_sym(sym0);
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {1, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_start_35_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->enroll_final_sym(sym0);
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {1, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_start_37_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->enroll_final_sym(sym0);
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {1, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_start_36_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->enroll_final_sym(sym0);
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {1, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_0_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Decl::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {38, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_0_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {38, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_0_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto x = reinterpret_cast<ptr<lang::data::Node::Decl::_T>>(res1.v_)->rc_from_this_poly<lang::data::Node::Decl::_T>();
        x.decref();
        auto x1 = reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Decl::_T>>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {39, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_0_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Decl::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x = reinterpret_cast<ptr<lang::data::Node::Decl::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Decl::_T>();
        x.decref();
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {39, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_2_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Decl::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {40, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_2_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {40, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_2_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto x = reinterpret_cast<ptr<lang::data::Node::Decl::_T>>(res1.v_)->rc_from_this_poly<lang::data::Node::Decl::_T>();
        x.decref();
        auto x1 = reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Decl::_T>>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {41, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_2_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Decl::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x = reinterpret_cast<ptr<lang::data::Node::Decl::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Decl::_T>();
        x.decref();
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {41, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto x = reinterpret_cast<ptr<lang::data::Node::SumId::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::SumId::_T>();
        x.decref();
        auto ret = make_rc_inc_ext<Option_T<rc_ptr<lang::data::Node::SumId::_T>>>(st->unw_arena_, Some<rc_ptr<lang::data::Node::SumId::_T>>(x));
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {42, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto ret = make_rc_inc_ext<Option_T<rc_ptr<lang::data::Node::SumId::_T>>>(st->unw_arena_, None<rc_ptr<lang::data::Node::SumId::_T>>());
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {42, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {43, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_9_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto x = rc_from_ptr_ext<Vec<rc_ptr<lang::data::Node::Param::_T>>>(reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Param::_T>>>>(res0.v_), st->unw_arena_);
        x.decref();
        auto ret = make_rc_inc_ext<Option_T<Vec_T<rc_ptr<lang::data::Node::Param::_T>>>>(st->unw_arena_, Some<Vec_T<rc_ptr<lang::data::Node::Param::_T>>>(x));
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {44, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_10_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto ret = make_rc_inc_ext<Option_T<Vec_T<rc_ptr<lang::data::Node::Param::_T>>>>(st->unw_arena_, None<Vec_T<rc_ptr<lang::data::Node::Param::_T>>>());
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {44, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_8_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        st->Sr_addr_[sr_len] = res1;
        ++sr_len;
        lang_rt::SymItem ret_sym = {45, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_4_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Param::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {46, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_5_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {46, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_6_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        auto x = reinterpret_cast<ptr<lang::data::Node::Param::_T>>(res2.v_)->rc_from_this_poly<lang::data::Node::Param::_T>();
        x.decref();
        auto x1 = reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Param::_T>>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {47, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_7_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Param::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x = reinterpret_cast<ptr<lang::data::Node::Param::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Param::_T>();
        x.decref();
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {47, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto res_item = lang_rt::Result_T(nullptr, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {48, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_11_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Mod::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {49, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_12_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {49, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_13_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto x = reinterpret_cast<ptr<lang::data::Node::Mod::_T>>(res1.v_)->rc_from_this_poly<lang::data::Node::Mod::_T>();
        x.decref();
        auto x1 = reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Mod::_T>>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {50, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_14_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Mod::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x = reinterpret_cast<ptr<lang::data::Node::Mod::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Mod::_T>();
        x.decref();
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {50, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_15_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Field::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {51, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_16_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {51, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_17_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto x = reinterpret_cast<ptr<lang::data::Node::Field::_T>>(res1.v_)->rc_from_this_poly<lang::data::Node::Field::_T>();
        x.decref();
        auto x1 = reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Field::_T>>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {52, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_3_18_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Field::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x = reinterpret_cast<ptr<lang::data::Node::Field::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Field::_T>();
        x.decref();
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {52, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_4_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<StrSlice>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {53, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_4_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {53, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_4_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        auto x_site = lang_rt::result_decode_token_bounds(res2);
        auto x = st->fetch_token(x_site.lo_);
        auto x1 = reinterpret_cast<ptr<Vec<StrSlice>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {54, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_4_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 2;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        ss_len = ss_len - 2;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        sr_len = sr_len - 2;
        auto vs = make_rc_inc_ext<Vec<StrSlice>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x_site = lang_rt::result_decode_token_bounds(res1);
        auto x = st->fetch_token(x_site.lo_);
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {54, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_9_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto ret = make_rc_inc_ext<bool>(st->unw_arena_, true);
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {55, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_9_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto ret = make_rc_inc_ext<bool>(st->unw_arena_, false);
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {55, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_9_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto res_item = lang_rt::Result_T(nullptr, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {56, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_10_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto ret = make_rc_inc_ext<bool>(st->unw_arena_, true);
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {57, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_10_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto ret = make_rc_inc_ext<bool>(st->unw_arena_, false);
        auto res_item = lang_rt::Result_T(ret, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {57, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_11_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 0;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        ss_len = ss_len - 0;
        sr_len = sr_len - 0;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Expr::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, start_pos));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {58, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_11_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {58, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_11_3_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        auto x = reinterpret_cast<ptr<lang::data::Node::Expr::_T>>(res2.v_)->rc_from_this_poly<lang::data::Node::Expr::_T>();
        x.decref();
        auto x1 = reinterpret_cast<ptr<Vec<rc_ptr<lang::data::Node::Expr::_T>>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {59, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_11_4_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<rc_ptr<lang::data::Node::Expr::_T>>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x = reinterpret_cast<ptr<lang::data::Node::Expr::_T>>(res0.v_)->rc_from_this_poly<lang::data::Node::Expr::_T>();
        x.decref();
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {59, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_11_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto res_item = lang_rt::Result_T(nullptr, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {60, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_13_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {61, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_13_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        auto x_site = lang_rt::result_decode_token_bounds(res2);
        auto x = st->fetch_token(x_site.lo_);
        auto x1 = reinterpret_cast<ptr<Vec<StrSlice>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {62, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_13_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<StrSlice>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x_site = lang_rt::result_decode_token_bounds(res0);
        auto x = st->fetch_token(x_site.lo_);
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {62, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_14_0_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        st->Sr_addr_[sr_len] = res0;
        ++sr_len;
        lang_rt::SymItem ret_sym = {63, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_14_1_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 3;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        auto sym1 = st->Ss_addr_[ss_len - 2];
        auto sym2 = st->Ss_addr_[ss_len - 3];
        ss_len = ss_len - 3;
        auto res0 = st->Sr_addr_[sr_len - 1];
        auto res1 = st->Sr_addr_[sr_len - 2];
        auto res2 = st->Sr_addr_[sr_len - 3];
        sr_len = sr_len - 3;
        auto x_site = lang_rt::result_decode_token_bounds(res2);
        auto x = st->fetch_token(x_site.lo_);
        auto x1 = reinterpret_cast<ptr<Vec<StrSlice>>>(res0.v_);
        x1->push_front(x);
        auto res_item = lang_rt::Result_T(x1, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {64, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

namespace lang::data::parser {
    __attribute__((noinline)) lang_rt::SymItem _parse_proc_14_2_0(lang_rt::ParserProcStatePtr st) {
        Int ss_len = st->Ss_len_;
        Int sr_len = st->Sr_len_;
        Int sb_len = st->Sb_len_;
        Int sv_len = st->Sv_len_;
        sv_len = sv_len - 1;
        Int start_pos = st->Sv_addr_[sv_len - 1].pos_;
        auto sym0 = st->Ss_addr_[ss_len - 1];
        ss_len = ss_len - 1;
        auto res0 = st->Sr_addr_[sr_len - 1];
        sr_len = sr_len - 1;
        auto vs = make_rc_inc_ext<Vec<StrSlice>>(st->unw_arena_, st->unw_arena_, 0, 1, _Vec_constr_internal());
        auto x_site = lang_rt::result_decode_token_bounds(res0);
        auto x = st->fetch_token(x_site.lo_);
        vs->push_back(x);
        auto res_item = lang_rt::Result_T(vs, lang_rt::TokenBounds(start_pos, res0.bounds_.hi_));
        st->Sr_addr_[sr_len] = res_item;
        ++sr_len;
        lang_rt::SymItem ret_sym = {64, start_pos};
        st->Ss_len_ = ss_len;
        st->Sr_len_ = sr_len;
        st->Sb_len_ = sb_len;
        st->Sv_len_ = sv_len;
        return ret_sym;
    }
}

lang_rt::ParserProcXforms lang::data::parser::proc_xform_by_prod_id() {
    auto ret = make_rc<Vec<lang_rt::ParserProcXform>>();
    ret->push_back(_parse_proc_0_4_0);
    ret->push_back(_parse_proc_1_0_0);
    ret->push_back(_parse_proc_2_4_0);
    ret->push_back(_parse_proc_3_19_0);
    ret->push_back(_parse_proc_4_4_0);
    ret->push_back(_parse_proc_5_0_0);
    ret->push_back(_parse_proc_6_0_0);
    ret->push_back(_parse_proc_7_0_0);
    ret->push_back(_parse_proc_8_0_0);
    ret->push_back(_parse_proc_9_3_0);
    ret->push_back(_parse_proc_10_2_0);
    ret->push_back(_parse_proc_11_5_0);
    ret->push_back(_parse_proc_12_0_0);
    ret->push_back(_parse_proc_13_3_0);
    ret->push_back(_parse_proc_14_3_0);
    ret->push_back(_parse_proc_start_30_0);
    ret->push_back(_parse_proc_start_31_0);
    ret->push_back(_parse_proc_start_34_0);
    ret->push_back(_parse_proc_start_35_0);
    ret->push_back(_parse_proc_start_37_0);
    ret->push_back(_parse_proc_start_36_0);
    ret->push_back(_parse_proc_0_0_0);
    ret->push_back(_parse_proc_0_1_0);
    ret->push_back(_parse_proc_0_2_0);
    ret->push_back(_parse_proc_0_3_0);
    ret->push_back(_parse_proc_2_0_0);
    ret->push_back(_parse_proc_2_1_0);
    ret->push_back(_parse_proc_2_2_0);
    ret->push_back(_parse_proc_2_3_0);
    ret->push_back(_parse_proc_3_1_0);
    ret->push_back(_parse_proc_3_2_0);
    ret->push_back(_parse_proc_3_0_0);
    ret->push_back(_parse_proc_3_9_0);
    ret->push_back(_parse_proc_3_10_0);
    ret->push_back(_parse_proc_3_8_0);
    ret->push_back(_parse_proc_3_4_0);
    ret->push_back(_parse_proc_3_5_0);
    ret->push_back(_parse_proc_3_6_0);
    ret->push_back(_parse_proc_3_7_0);
    ret->push_back(_parse_proc_3_3_0);
    ret->push_back(_parse_proc_3_11_0);
    ret->push_back(_parse_proc_3_12_0);
    ret->push_back(_parse_proc_3_13_0);
    ret->push_back(_parse_proc_3_14_0);
    ret->push_back(_parse_proc_3_15_0);
    ret->push_back(_parse_proc_3_16_0);
    ret->push_back(_parse_proc_3_17_0);
    ret->push_back(_parse_proc_3_18_0);
    ret->push_back(_parse_proc_4_0_0);
    ret->push_back(_parse_proc_4_1_0);
    ret->push_back(_parse_proc_4_2_0);
    ret->push_back(_parse_proc_4_3_0);
    ret->push_back(_parse_proc_9_1_0);
    ret->push_back(_parse_proc_9_2_0);
    ret->push_back(_parse_proc_9_0_0);
    ret->push_back(_parse_proc_10_0_0);
    ret->push_back(_parse_proc_10_1_0);
    ret->push_back(_parse_proc_11_1_0);
    ret->push_back(_parse_proc_11_2_0);
    ret->push_back(_parse_proc_11_3_0);
    ret->push_back(_parse_proc_11_4_0);
    ret->push_back(_parse_proc_11_0_0);
    ret->push_back(_parse_proc_13_0_0);
    ret->push_back(_parse_proc_13_1_0);
    ret->push_back(_parse_proc_13_2_0);
    ret->push_back(_parse_proc_14_0_0);
    ret->push_back(_parse_proc_14_1_0);
    ret->push_back(_parse_proc_14_2_0);
    return ret;
}

lang_rt::ParserSymByName lang::data::parser::start_marker_by_name() {
    lang_rt::ParserSymByName ret;
    ret.insert(make_pair("Module", 24));
    ret.insert(make_pair("Decl", 25));
    ret.insert(make_pair("Field", 26));
    ret.insert(make_pair("Expr", 27));
    ret.insert(make_pair("Id", 28));
    ret.insert(make_pair("SumId", 29));
    return ret;
}

lang_rt::ParserSymId lang::data::parser::term_tok_to_sym(lang_rt::TokenId tok) {
    switch (tok) {
        case 0: {
            return 2;
        }
        case 1: {
            return 3;
        }
        case 2: {
            return 4;
        }
        case 3: {
            return 5;
        }
        case 4: {
            return 6;
        }
        case 5: {
            return 7;
        }
        case 6: {
            return 8;
        }
        case 7: {
            return 9;
        }
        case 8: {
            return 10;
        }
        case 9: {
            return 11;
        }
        case 10: {
            return 12;
        }
        case 11: {
            return 13;
        }
        case 12: {
            return 14;
        }
        case 13: {
            return 15;
        }
        case 14: {
            return 16;
        }
        case 15: {
            return 17;
        }
        case 16: {
            return 18;
        }
        case 17: {
            return 19;
        }
        case 18: {
            return 20;
        }
        case 19: {
            return 21;
        }
        case 20: {
            return 22;
        }
        case 21: {
            return 23;
        }
        default: {
            AX();
        }
    }
}

lang_rt::ParserSymId lang::data::parser::sym_to_recur_step(lang_rt::ParserSymId sym) {
    switch (sym) {
        case 30: {
            return 65;
        }
        case 31: {
            return 66;
        }
        case 32: {
            return 67;
        }
        case 33: {
            return 68;
        }
        case 34: {
            return 69;
        }
        case 35: {
            return 70;
        }
        case 36: {
            return 71;
        }
        case 37: {
            return 72;
        }
        case 1: {
            return 73;
        }
        case 38: {
            return 74;
        }
        case 39: {
            return 75;
        }
        case 40: {
            return 76;
        }
        case 41: {
            return 77;
        }
        case 42: {
            return 78;
        }
        case 43: {
            return 79;
        }
        case 44: {
            return 80;
        }
        case 45: {
            return 81;
        }
        case 46: {
            return 82;
        }
        case 47: {
            return 83;
        }
        case 48: {
            return 84;
        }
        case 49: {
            return 85;
        }
        case 50: {
            return 86;
        }
        case 51: {
            return 87;
        }
        case 52: {
            return 88;
        }
        case 53: {
            return 89;
        }
        case 54: {
            return 90;
        }
        case 55: {
            return 91;
        }
        case 56: {
            return 92;
        }
        case 57: {
            return 93;
        }
        case 58: {
            return 94;
        }
        case 59: {
            return 95;
        }
        case 60: {
            return 96;
        }
        case 61: {
            return 97;
        }
        case 62: {
            return 98;
        }
        case 63: {
            return 99;
        }
        case 64: {
            return 100;
        }
        default: {
            AX();
        }
    }
}

string lang::data::parser::sym_to_debug_string(lang_rt::ParserSymId sym) {
    switch (sym) {
        case 0: {
            return "$$";
        }
        case 1: {
            return "&&";
        }
        case 2: {
            return "idBase";
        }
        case 3: {
            return "`.`";
        }
        case 4: {
            return "`:`";
        }
        case 5: {
            return "`;`";
        }
        case 6: {
            return "`::`";
        }
        case 7: {
            return "`{`";
        }
        case 8: {
            return "`}`";
        }
        case 9: {
            return "`(`";
        }
        case 10: {
            return "`)`";
        }
        case 11: {
            return "`,`";
        }
        case 12: {
            return "`^`";
        }
        case 13: {
            return "`<:`";
        }
        case 14: {
            return "`def`";
        }
        case 15: {
            return "`enum`";
        }
        case 16: {
            return "`namespace`";
        }
        case 17: {
            return "`Type`";
        }
        case 18: {
            return "`mut`";
        }
        case 19: {
            return "`xform`";
        }
        case 20: {
            return "`visit`";
        }
        case 21: {
            return "`#include`";
        }
        case 22: {
            return "`no_hash`";
        }
        case 23: {
            return "str_lit";
        }
        case 24: {
            return "&Module";
        }
        case 25: {
            return "&Decl";
        }
        case 26: {
            return "&Field";
        }
        case 27: {
            return "&Expr";
        }
        case 28: {
            return "&Id";
        }
        case 29: {
            return "&SumId";
        }
        case 30: {
            return "Module";
        }
        case 31: {
            return "Decl";
        }
        case 32: {
            return "Mod";
        }
        case 33: {
            return "Param";
        }
        case 34: {
            return "Field";
        }
        case 35: {
            return "Expr";
        }
        case 36: {
            return "SumId";
        }
        case 37: {
            return "Id";
        }
        case 38: {
            return "X0=(#T2[Decl::eps])";
        }
        case 39: {
            return "Iter(Decl)";
        }
        case 40: {
            return "X2=(#B2[Decl::eps])";
        }
        case 41: {
            return "Iter(Decl)";
        }
        case 42: {
            return "X4=((_ `<:` _ SumId)?)";
        }
        case 43: {
            return "X5=(_ `<:` _ SumId)";
        }
        case 44: {
            return "X6=((`(` #L[Param::`,` _] `)`)?)";
        }
        case 45: {
            return "X7=(`(` #L[Param::`,` _] `)`)";
        }
        case 46: {
            return "X8=(#L[Param::`,` _])";
        }
        case 47: {
            return "Iter(Param)";
        }
        case 48: {
            return "X10=(`,` _)";
        }
        case 49: {
            return "X11=(#L[Mod::_::])";
        }
        case 50: {
            return "Iter(Mod)";
        }
        case 51: {
            return "X13=(#B[Field::eps])";
        }
        case 52: {
            return "Iter(Field)";
        }
        case 53: {
            return "X15=(#B[idBase::`;`::])";
        }
        case 54: {
            return "Iter(idBase)";
        }
        case 55: {
            return "X17=((_ `no_hash`)?)";
        }
        case 56: {
            return "X18=(_ `no_hash`)";
        }
        case 57: {
            return "X19=(`^`?)";
        }
        case 58: {
            return "X20=(#L[Expr::`,` _])";
        }
        case 59: {
            return "Iter(Expr)";
        }
        case 60: {
            return "X22=(`,` _)";
        }
        case 61: {
            return "X23=(#L[idBase::+`.`])";
        }
        case 62: {
            return "Iter(idBase)";
        }
        case 63: {
            return "X25=(#L[idBase::+`::`])";
        }
        case 64: {
            return "Iter(idBase)";
        }
        case 65: {
            return "RecurStep(Module)";
        }
        case 66: {
            return "RecurStep(Decl)";
        }
        case 67: {
            return "RecurStep(Mod)";
        }
        case 68: {
            return "RecurStep(Param)";
        }
        case 69: {
            return "RecurStep(Field)";
        }
        case 70: {
            return "RecurStep(Expr)";
        }
        case 71: {
            return "RecurStep(SumId)";
        }
        case 72: {
            return "RecurStep(Id)";
        }
        case 73: {
            return "RecurStep(&&)";
        }
        case 74: {
            return "RecurStep(X0=(#T2[Decl::eps]))";
        }
        case 75: {
            return "RecurStep(Iter(Decl))";
        }
        case 76: {
            return "RecurStep(X2=(#B2[Decl::eps]))";
        }
        case 77: {
            return "RecurStep(Iter(Decl))";
        }
        case 78: {
            return "RecurStep(X4=((_ `<:` _ SumId)?))";
        }
        case 79: {
            return "RecurStep(X5=(_ `<:` _ SumId))";
        }
        case 80: {
            return "RecurStep(X6=((`(` #L[Param::`,` _] `)`)?))";
        }
        case 81: {
            return "RecurStep(X7=(`(` #L[Param::`,` _] `)`))";
        }
        case 82: {
            return "RecurStep(X8=(#L[Param::`,` _]))";
        }
        case 83: {
            return "RecurStep(Iter(Param))";
        }
        case 84: {
            return "RecurStep(X10=(`,` _))";
        }
        case 85: {
            return "RecurStep(X11=(#L[Mod::_::]))";
        }
        case 86: {
            return "RecurStep(Iter(Mod))";
        }
        case 87: {
            return "RecurStep(X13=(#B[Field::eps]))";
        }
        case 88: {
            return "RecurStep(Iter(Field))";
        }
        case 89: {
            return "RecurStep(X15=(#B[idBase::`;`::]))";
        }
        case 90: {
            return "RecurStep(Iter(idBase))";
        }
        case 91: {
            return "RecurStep(X17=((_ `no_hash`)?))";
        }
        case 92: {
            return "RecurStep(X18=(_ `no_hash`))";
        }
        case 93: {
            return "RecurStep(X19=(`^`?))";
        }
        case 94: {
            return "RecurStep(X20=(#L[Expr::`,` _]))";
        }
        case 95: {
            return "RecurStep(Iter(Expr))";
        }
        case 96: {
            return "RecurStep(X22=(`,` _))";
        }
        case 97: {
            return "RecurStep(X23=(#L[idBase::+`.`]))";
        }
        case 98: {
            return "RecurStep(Iter(idBase))";
        }
        case 99: {
            return "RecurStep(X25=(#L[idBase::+`::`]))";
        }
        case 100: {
            return "RecurStep(Iter(idBase))";
        }
        default: {
            AX();
        }
    }
}

Int lang::data::parser::sym_to_num_attrs(lang_rt::ParserSymId sym) {
    switch (sym) {
        case 1: {
            return 0;
        }
        case 2: {
            return 0;
        }
        case 3: {
            return 0;
        }
        case 4: {
            return 0;
        }
        case 5: {
            return 0;
        }
        case 6: {
            return 0;
        }
        case 7: {
            return 0;
        }
        case 8: {
            return 0;
        }
        case 9: {
            return 0;
        }
        case 10: {
            return 0;
        }
        case 11: {
            return 0;
        }
        case 12: {
            return 0;
        }
        case 13: {
            return 0;
        }
        case 14: {
            return 0;
        }
        case 15: {
            return 0;
        }
        case 16: {
            return 0;
        }
        case 17: {
            return 0;
        }
        case 18: {
            return 0;
        }
        case 19: {
            return 0;
        }
        case 20: {
            return 0;
        }
        case 21: {
            return 0;
        }
        case 22: {
            return 0;
        }
        case 23: {
            return 0;
        }
        case 24: {
            return 0;
        }
        case 25: {
            return 0;
        }
        case 26: {
            return 0;
        }
        case 27: {
            return 0;
        }
        case 28: {
            return 0;
        }
        case 29: {
            return 0;
        }
        case 30: {
            return 0;
        }
        case 31: {
            return 0;
        }
        case 32: {
            return 0;
        }
        case 33: {
            return 0;
        }
        case 34: {
            return 0;
        }
        case 35: {
            return 0;
        }
        case 36: {
            return 0;
        }
        case 37: {
            return 0;
        }
        case 38: {
            return 0;
        }
        case 39: {
            return 0;
        }
        case 40: {
            return 0;
        }
        case 41: {
            return 0;
        }
        case 42: {
            return 0;
        }
        case 43: {
            return 0;
        }
        case 44: {
            return 0;
        }
        case 45: {
            return 0;
        }
        case 46: {
            return 0;
        }
        case 47: {
            return 0;
        }
        case 48: {
            return 0;
        }
        case 49: {
            return 0;
        }
        case 50: {
            return 0;
        }
        case 51: {
            return 0;
        }
        case 52: {
            return 0;
        }
        case 53: {
            return 0;
        }
        case 54: {
            return 0;
        }
        case 55: {
            return 0;
        }
        case 56: {
            return 0;
        }
        case 57: {
            return 0;
        }
        case 58: {
            return 0;
        }
        case 59: {
            return 0;
        }
        case 60: {
            return 0;
        }
        case 61: {
            return 0;
        }
        case 62: {
            return 0;
        }
        case 63: {
            return 0;
        }
        case 64: {
            return 0;
        }
        default: {
            AX();
        }
    }
}

string lang::data::parser::attr_to_debug_string(lang_rt::ParserSymId sym, Int attr_ind) {
    switch (sym) {
        case 1: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 2: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 3: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 4: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 5: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 6: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 7: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 8: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 9: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 10: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 11: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 12: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 13: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 14: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 15: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 16: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 17: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 18: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 19: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 20: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 21: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 22: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 23: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 24: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 25: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 26: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 27: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 28: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 29: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 30: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 31: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 32: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 33: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 34: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 35: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 36: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 37: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 38: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 39: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 40: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 41: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 42: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 43: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 44: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 45: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 46: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 47: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 48: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 49: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 50: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 51: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 52: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 53: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 54: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 55: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 56: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 57: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 58: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 59: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 60: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 61: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 62: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 63: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        case 64: {
            switch (attr_ind) {
                default: {
                    AX("Not found: {}, {}", sym, attr_ind);
                }
            }
            break;
        }
        default: {
            AX();
        }
    }
}

inline __attribute__((always_inline)) Int lang::data::lexer::body::proc_mode_loop_opt(ptr<lang_rt::LexerModeDesc> mode, ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos) {
    lang_rt::SymItemVec emit_dst_sub;
    bool read_eof = false;
    Int in_i = mode_start_pos;
    ptr<Ch> in_data = st->in_->data_.begin();
    Int in_data_len = st->in_->data_len_;
    auto label_ids_ascii = st->label_ids_ascii_->begin();
    Int tok_lo;
    Int tok_hi;
    rc_ptr<lang_rt::LexWhitespaceState> ws_state_rc;
    lang_rt::LexWhitespaceState * ws_state = nullptr;
    if (mode->ws_sig_) {
        ws_state_rc = make_rc<lang_rt::LexWhitespaceState>(st, st->tok_to_sym_, mode_buf_pos, in_data, mode->ws_newline_ind_, mode->ws_indent_ind_, mode->ws_dedent_ind_, mode->ws_err_mixed_indent_ind_, mode->ws_err_text_after_lc_ind_, mode->ws_err_delim_mismatch_ind_);
        ws_state = ws_state_rc.get();
    }
    for (cc_nop(); true; cc_nop()) {
        tok_lo = in_i;
        lang_rt::DFAVertexId v = 0;
        lang_rt::DFAActionId best_act = lang_rt::DFATable::NO_ACTION;
        lang_rt::TokenId best_tok;
        for (cc_nop(); true; cc_nop()) {
            lang_rt::TokenId cl = lang_rt::lexer_char_to_label(in_data, in_i, in_data_len, label_ids_ascii, st);
            v = step(v, cl);
            if (__builtin_expect(v == lang_rt::DFATable::NO_VERTEX, 0)) {
                break;
            }
            if (__builtin_expect(cl == lang_rt::DFATable::EOF_LABEL, 0)) {
                read_eof = true;
            }
            if (__builtin_expect(!read_eof, 1)) {
                in_i++;
            }
            auto acc_tok = acc(v);
            if (acc_tok.first != lang_rt::DFATable::NO_ACTION) {
                tok_hi = in_i;
                best_act = acc_tok.first;
                best_tok = acc_tok.second;
            }
        }
        in_i = tok_lo;
        lang_rt::lexer_state_proc_update_pre(best_act, best_tok, tok_lo, tok_hi, in_i, read_eof, st);
        IntPair new_mode_dir = step_exec(st, emit_dst, ws_state, best_act, best_tok, in_i, tok_lo, tok_hi);
        if (__builtin_expect(new_mode_dir.first == lang_rt::DFATable::NEW_MODE_POP_EMIT, 0)) {
            st->enqueue_emit_ext(emit_dst, ws_state, new_mode_dir.second, mode_buf_pos, in_i, true);
            if (!!ws_state) {
                ws_state->finish(tok_hi, emit_dst);
            }
            return in_i;
        }
        if (__builtin_expect(new_mode_dir.first == lang_rt::DFATable::NEW_MODE_POP_EXTRACT, 0)) {
            st->extract_comment(mode_buf_pos, in_i);
            if (!!ws_state) {
                ws_state->finish(tok_hi, emit_dst);
            }
            return in_i;
        }
        if (__builtin_expect(new_mode_dir.first == lang_rt::DFATable::NEW_MODE_POP, 0)) {
            if (!!ws_state) {
                ws_state->finish(tok_hi, emit_dst);
            }
            return in_i;
        }
        if (__builtin_expect(new_mode_dir.first >= 0, 0)) {
            auto desc_new = st->mode_descs_->operator[](new_mode_dir.first);
            in_i = lexer_proc_mode_loop(desc_new.get(), st, &emit_dst_sub, in_i, new_mode_dir.second);
            lang_rt::lex_queue_pull_sub(st, emit_dst, &emit_dst_sub, ws_state);
        }
        if (__builtin_expect(read_eof, 0)) {
            lang_rt::lexer_raise_nonempty_mode_stack(st, in_i);
        }
    }
}

inline __attribute__((always_inline)) Int lang::data::lexer::comment_single::proc_mode_loop_opt(ptr<lang_rt::LexerModeDesc> mode, ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos) {
    lang_rt::SymItemVec emit_dst_sub;
    Int in_i = mode_start_pos;
    ptr<Ch> in_data = st->in_->data_.begin();
    Int in_data_len = st->in_->data_len_;
    Int tok_lo;
    Int tok_hi;
    ptr<lang_rt::LexWhitespaceState> ws_state = nullptr;
    for (cc_nop(); true; cc_nop()) {
        tok_lo = in_i;
        lang_rt::DFAActionId best_act = lang_rt::DFATable::NO_ACTION;
        lang_rt::TokenId best_tok;
        for (cc_nop(); true; cc_nop()) {
            Ch curr = -1;
            if (__builtin_expect(in_i == in_data_len, 0)) {
                {
                    lexer_raise_unexpected_eof(st, in_i);
                }
            } else {
                curr = in_data[in_i];
            }
            if (__builtin_expect(curr == 10, 0)) {
                {
                    tok_lo = in_i;
                    tok_hi = in_i + 1;
                    best_act = 0;
                    best_tok = lang_rt::NO_TOKEN;
                    break;
                }
            }
            ++in_i;
        }
        IntPair new_mode_dir = mode->step_exec_fn_(st, emit_dst, ws_state, best_act, best_tok, in_i, tok_lo, tok_hi);
        if (__builtin_expect(new_mode_dir.first == lang_rt::DFATable::NEW_MODE_POP_EMIT, 0)) {
            st->enqueue_emit_ext(emit_dst, ws_state, new_mode_dir.second, mode_buf_pos, in_i, true);
            return in_i;
        }
        if (__builtin_expect(new_mode_dir.first == lang_rt::DFATable::NEW_MODE_POP_EXTRACT, 0)) {
            st->extract_comment(mode_buf_pos, in_i);
            return in_i;
        }
        if (__builtin_expect(new_mode_dir.first == lang_rt::DFATable::NEW_MODE_POP, 0)) {
            return in_i;
        }
        if (__builtin_expect(new_mode_dir.first >= 0, 0)) {
            auto desc_new = st->mode_descs_->operator[](new_mode_dir.first);
            in_i = lexer_proc_mode_loop(desc_new.get(), st, &emit_dst_sub, in_i, new_mode_dir.second);
            lang_rt::lex_queue_pull_sub(st, emit_dst, &emit_dst_sub, ws_state);
        }
    }
}

lang::data::LangDesc_T lang::data::init() {
    auto ret = make_rc<lang::data::LangDesc>();
    ret->lexer_mode_descs_ = make_rc<Vec<lang_rt::LexerModeDesc_T>>();
    auto body = make_rc<lang_rt::LexerModeDesc>();
    body->step_fn_ = lexer::body::step;
    body->acc_fn_ = lexer::body::acc;
    body->step_exec_fn_ = lexer::body::step_exec;
    body->proc_mode_loop_opt_fn_ = lexer::body::proc_mode_loop_opt;
    ret->lexer_mode_descs_->push(body);
    body->ws_sig_ = false;
    auto comment_single = make_rc<lang_rt::LexerModeDesc>();
    comment_single->step_fn_ = lexer::comment_single::step;
    comment_single->acc_fn_ = lexer::comment_single::acc;
    comment_single->step_exec_fn_ = lexer::comment_single::step_exec;
    comment_single->proc_mode_loop_opt_fn_ = lexer::comment_single::proc_mode_loop_opt;
    ret->lexer_mode_descs_->push(comment_single);
    comment_single->ws_sig_ = false;
    ret->label_ids_ascii_ = lexer::label_ids_ascii();
    ret->label_ids_unicode_ = lexer::label_ids_unicode();
    ret->lexer_main_mode_ = 0;
    ret->parser_desc_ = make_rc<lang_rt::ParserDesc>();
    ret->parser_desc_->start_vertex_ = 0;
    ret->parser_desc_->main_sym_ = "Module";
    ret->parser_desc_->start_full_sym_ = 1;
    ret->parser_desc_->right_end_marker_ = 0;
    ret->parser_desc_->lr_k_ = 1;
    ret->parser_desc_->term_tok_to_sym_ = parser::term_tok_to_sym;
    ret->parser_desc_->sym_to_recur_step_ = parser::sym_to_recur_step;
    ret->parser_desc_->start_marker_by_name_ = parser::start_marker_by_name();
    ret->parser_desc_->proc_xform_by_prod_id_ = parser::proc_xform_by_prod_id();
    ret->parser_desc_->sym_to_debug_string_ = parser::sym_to_debug_string;
    ret->parser_desc_->sym_to_num_attrs_ = parser::sym_to_num_attrs;
    ret->parser_desc_->attr_to_debug_string_ = parser::attr_to_debug_string;
    ret->parser_desc_->cps_flat_diff_max_ = 0;
    return ret;
}
