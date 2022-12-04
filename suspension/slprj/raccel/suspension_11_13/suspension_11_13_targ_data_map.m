  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 182;
      section.data(182)  = dumData; %prealloc
      
	  ;% rtP.cfs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.cft
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.crs
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.crt
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.iyy
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.kfs
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.kft
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.krs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.krt
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.lf
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.lr
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.mc
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.mf
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.mr
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.Integrator2_IC
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.Integrator2_IC_clvdfmmn2j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.Integrator2_IC_icgsg0ay1z
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.Integrator2_IC_izuk2xqhyn
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.Integrator1_IC
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.Integrator1_IC_kd2vqetgqx
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.Integrator1_IC_ds3xtg3mkc
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.Integrator1_IC_n5ffr0esli
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.Integrator5_IC
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.Integrator5_IC_iosnn25ku4
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.Integrator5_IC_pbm1hhtqvq
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.Integrator5_IC_fmb14y3cnw
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtP.Integrator3_IC
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtP.Gain_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtP.Integrator3_IC_h0aez5va4u
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtP.Gain_Gain_kfgmdgojqi
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtP.Integrator3_IC_mc4a1wd42u
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtP.Gain_Gain_lniewnxiui
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtP.Integrator3_IC_ghtohsff01
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtP.Gain_Gain_ncm0idjmjp
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtP.Integrator7_IC
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtP.Integrator7_IC_bzmaczyftv
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtP.Integrator7_IC_hsyswncslp
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtP.Integrator7_IC_jvqwwdf42v
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtP.Integrator_IC
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtP.Integrator4_IC
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtP.Integrator6_IC
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtP.Gain9_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtP.Gain9_Gain_mm4lob34jr
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtP.SignalGenerator_Amplitude
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtP.SignalGenerator_Frequency
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtP.Step_Time
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtP.Step_Y0
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtP.Step_YFinal
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtP.Step1_Time
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtP.Step1_Y0
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtP.Step1_YFinal
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtP.Gain_Gain_iit24j4qxf
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% rtP.Gain9_Gain_dqygs1aszs
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% rtP.TransportDelay1_Delay
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% rtP.TransportDelay1_InitOutput
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% rtP.Gain9_Gain_okhtvkgje5
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% rtP.SignalGenerator_Amplitude_eudi0mxlsb
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% rtP.SignalGenerator_Frequency_a50i2lvmye
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% rtP.Step_Time_mvs0g1sev0
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% rtP.Step_Y0_iz131rho11
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% rtP.Step_YFinal_hqre2tmqod
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% rtP.Step1_Time_jphzf3vxvl
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% rtP.Step1_Y0_pl0xadtajh
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% rtP.Step1_YFinal_awmv2dzpr0
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% rtP.Integrator_IC_gsjia5qsst
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% rtP.Integrator4_IC_cigt4hske3
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% rtP.Integrator6_IC_h1i5q5y2jf
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% rtP.Gain9_Gain_jglnwjr1da
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% rtP.Gain9_Gain_buqm2zp1xy
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% rtP.SignalGenerator_Amplitude_fbk2hkdqfm
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% rtP.SignalGenerator_Frequency_i1c2jxsnux
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% rtP.Step_Time_kxn30foah1
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% rtP.Step_Y0_dalzojkna3
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% rtP.Step_YFinal_ikormlakvz
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% rtP.Step1_Time_fxtabt0hzy
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% rtP.Step1_Y0_ihbov1sa5i
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% rtP.Step1_YFinal_dudehtwvxl
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% rtP.Gain_Gain_cec0fvfroz
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% rtP.TransportDelay_Delay_iap2op2zgh
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% rtP.TransportDelay_InitOutput_ea1344nau0
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% rtP.Gain9_Gain_fzv5tmgqw5
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% rtP.TransportDelay1_Delay_e5t1cmi5b5
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% rtP.TransportDelay1_InitOutput_etxwutwb0s
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% rtP.Gain9_Gain_hick3dd3rf
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% rtP.SignalGenerator_Amplitude_jqvsffusiy
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% rtP.SignalGenerator_Frequency_o1bkitcbhj
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% rtP.Step_Time_d15jg5xwxc
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% rtP.Step_Y0_frz4o3t2qo
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% rtP.Step_YFinal_mvwpnjqziy
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% rtP.Step1_Time_a0qbodifis
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% rtP.Step1_Y0_dkhrl3hyib
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% rtP.Step1_YFinal_iovgwjmexk
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% rtP.Saturation_UpperSat_nmc40qz4uh
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% rtP.Saturation_LowerSat_avfz2gn5tr
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% rtP.Integrator_IC_e0ie1xk1t1
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% rtP.Integrator4_IC_bdrpcflxad
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% rtP.Integrator6_IC_ktopl34sag
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% rtP.SignalGenerator_Amplitude_guqpb23tpp
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 101;
	
	  ;% rtP.SignalGenerator_Frequency_m0wbhyregv
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 102;
	
	  ;% rtP.Step_Time_facad21pf1
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 103;
	
	  ;% rtP.Step_Y0_jeywlji0bq
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 104;
	
	  ;% rtP.Step_YFinal_pnkyifhjta
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 105;
	
	  ;% rtP.Step1_Time_ia1tcvue3b
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 106;
	
	  ;% rtP.Step1_Y0_dmjz2ujtxq
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 107;
	
	  ;% rtP.Step1_YFinal_htin21ftgl
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 108;
	
	  ;% rtP.Gain_Gain_goppgbgrif
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 109;
	
	  ;% rtP.TransportDelay_Delay_eqwrqaxknp
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 110;
	
	  ;% rtP.TransportDelay_InitOutput_cflcileqko
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 111;
	
	  ;% rtP.TransportDelay1_Delay_didz0ysu0l
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 112;
	
	  ;% rtP.TransportDelay1_InitOutput_gsatvdlebd
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 113;
	
	  ;% rtP.SignalGenerator_Amplitude_fh5dm5543u
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 114;
	
	  ;% rtP.SignalGenerator_Frequency_ji325krl5r
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 115;
	
	  ;% rtP.Step_Time_bwraqreocj
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 116;
	
	  ;% rtP.Step_Y0_kdc10z30qv
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 117;
	
	  ;% rtP.Step_YFinal_kuwyhln44e
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 118;
	
	  ;% rtP.Step1_Time_oqjaobvqli
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 119;
	
	  ;% rtP.Step1_Y0_cerqkmzec3
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 120;
	
	  ;% rtP.Step1_YFinal_gb5ur2tfsw
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 121;
	
	  ;% rtP.Saturation_UpperSat_lolh1xkie1
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 122;
	
	  ;% rtP.Saturation_LowerSat_f31445vevn
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 123;
	
	  ;% rtP.Integrator_IC_dw0j2rkbay
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 124;
	
	  ;% rtP.Integrator4_IC_me53n3zt1r
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 125;
	
	  ;% rtP.Integrator6_IC_osnmqre5ia
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 126;
	
	  ;% rtP.SignalGenerator_Amplitude_g44bgrrq31
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 127;
	
	  ;% rtP.SignalGenerator_Frequency_k0uyvcxxrq
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 128;
	
	  ;% rtP.Step_Time_n2vdheg15a
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 129;
	
	  ;% rtP.Step_Y0_cl32zzujww
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 130;
	
	  ;% rtP.Step_YFinal_ioed2vlmyx
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 131;
	
	  ;% rtP.Step1_Time_nrjoxzvdeh
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 132;
	
	  ;% rtP.Step1_Y0_nln5lb0z31
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 133;
	
	  ;% rtP.Step1_YFinal_kymwsjvu4f
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 134;
	
	  ;% rtP.Gain_Gain_ldzy4oavtu
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 135;
	
	  ;% rtP.TransportDelay_Delay_frmicxredo
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 136;
	
	  ;% rtP.TransportDelay_InitOutput_jhwmjqic5y
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 137;
	
	  ;% rtP.TransportDelay1_Delay_oufsiqvqky
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 138;
	
	  ;% rtP.TransportDelay1_InitOutput_i1rr3k5rot
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 139;
	
	  ;% rtP.SignalGenerator_Amplitude_fqfftxwwhb
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 140;
	
	  ;% rtP.SignalGenerator_Frequency_esatikfj0t
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 141;
	
	  ;% rtP.Step_Time_ief3iynhma
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 142;
	
	  ;% rtP.Step_Y0_hbpv5svquz
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 143;
	
	  ;% rtP.Step_YFinal_jsjbxkocsk
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 144;
	
	  ;% rtP.Step1_Time_iwq124hwmz
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 145;
	
	  ;% rtP.Step1_Y0_cxcqlzhc5m
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 146;
	
	  ;% rtP.Step1_YFinal_kconhbutz2
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 147;
	
	  ;% rtP.Saturation_UpperSat_gro4c0twir
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 148;
	
	  ;% rtP.Saturation_LowerSat_k5krwyec4a
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 149;
	
	  ;% rtP.Constant_Value
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 150;
	
	  ;% rtP.Constant1_Value
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 151;
	
	  ;% rtP.Constant_Value_js1bbvwx44
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 152;
	
	  ;% rtP.Constant1_Value_boctjgkrac
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 153;
	
	  ;% rtP.Constant_Value_pcb3rcescv
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 154;
	
	  ;% rtP.Constant1_Value_az0xekyfmv
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 155;
	
	  ;% rtP.Constant_Value_i5zgqe2wta
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 156;
	
	  ;% rtP.Constant1_Value_ojyctmrwrg
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 157;
	
	  ;% rtP.Constant_Value_gnxcisvqkz
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 158;
	
	  ;% rtP.Constant1_Value_krl1nmx5tb
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 159;
	
	  ;% rtP.Constant2_Value
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 160;
	
	  ;% rtP.Constant3_Value
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 161;
	
	  ;% rtP.Constant_Value_j5obrm202k
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 162;
	
	  ;% rtP.Constant1_Value_gwq5uspikg
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 163;
	
	  ;% rtP.Constant2_Value_npn4i05u3n
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 164;
	
	  ;% rtP.Constant3_Value_f5rovkb5n0
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 165;
	
	  ;% rtP.Constant_Value_p33xk1nt0c
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 166;
	
	  ;% rtP.Constant1_Value_iucvhmftri
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 167;
	
	  ;% rtP.Constant2_Value_pwplpsvmqw
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 168;
	
	  ;% rtP.Constant3_Value_iyzr1ezzvq
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 169;
	
	  ;% rtP.Constant_Value_hzj4wvktxf
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 170;
	
	  ;% rtP.Constant1_Value_kxn2zcp3ig
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 171;
	
	  ;% rtP.Constant2_Value_icdxaqrdvn
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 172;
	
	  ;% rtP.Constant3_Value_ej5wa025ni
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 173;
	
	  ;% rtP.Constant_Value_f34x3v0gei
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 174;
	
	  ;% rtP.Constant1_Value_gbvvgkwbnv
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 175;
	
	  ;% rtP.Constant_Value_b0ss3j0del
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 176;
	
	  ;% rtP.Constant1_Value_mr12qranuj
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 177;
	
	  ;% rtP.Constant_Value_ckbzzxjmxu
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 178;
	
	  ;% rtP.Constant1_Value_b5q3lrb3hv
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 179;
	
	  ;% rtP.Constant_Value_ivnvcq4oxu
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 180;
	
	  ;% rtP.Constant1_Value_mj2nmzyxxv
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 181;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 336;
      section.data(336)  = dumData; %prealloc
      
	  ;% rtB.ckhfos3d5d
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ctr3nygjvu
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.gihker42li
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.fgv0iw5io4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.jbu2t0zvvf
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.igbnss0o0f
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.cwi04tubt0
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.khpnmtgkim
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.mcgc55onte
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.lxtjreczcv
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.g2y0j4r4xp
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.ivrqxfr4p2
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.pawhsqlpds
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.j4ut0d52c5
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.ppy2yksd3e
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.dkbiwipjls
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.cwjqfhgoni
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.c1vwcagcv1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtB.ohobmojlqf
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtB.ovbcvugezj
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtB.jvzmdt5nzv
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtB.f2micsnrzs
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtB.ncrqgav3ps
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtB.aacyykkcvt
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtB.cur3cpy4nj
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtB.bvxzxcagw2
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtB.ges324gpjn
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtB.bv1suo0epr
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtB.kxytv3kagx
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtB.oy1jpf0hjr
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtB.hp1xxrtth5
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtB.oop0utfex2
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtB.oe3cby5so1
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtB.oshpndvkvq
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtB.jn21fsqluy
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtB.kw2jpjnlx1
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtB.n0e2xw5ck4
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtB.nbl2g1zklu
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtB.kgnzsa0lua
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtB.pw4bunpnxj
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtB.husvkqrr5g
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtB.iyiruigdqg
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtB.fir0lhcte1
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtB.pizchjzfbl
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtB.ew12od4jo4
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtB.k0rxxdqz3n
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtB.cbs2crqgjz
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtB.obhdstfloy
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtB.jobgxinndp
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtB.c35haqaiz1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtB.nrrfaz4txr
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtB.dnyl1ewlz0
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtB.li3nwnnqnt
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% rtB.ds1h3d1hfe
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% rtB.gpq11xa2q4
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% rtB.hossx3vmtu
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% rtB.mrgu1y10yn
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% rtB.lgzpfz3f3w
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% rtB.dj1wmcvi0i
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% rtB.jrhinsm5vq
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% rtB.mjw5ulp0gg
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% rtB.o50fwsfxem
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% rtB.hb00ru01fq
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% rtB.p4n4hpe1b1
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% rtB.hee11uhjj0
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% rtB.dshdg4oozs
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% rtB.pc2izoasnn
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% rtB.lw44fbjzmd
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% rtB.ap5mzmnsci
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% rtB.m2jdcg5lrr
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% rtB.kxzs0jwwpz
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% rtB.n3tlanomdr
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% rtB.jjfmleyq2w
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% rtB.ffhybcifud
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% rtB.ou1c3oxils
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% rtB.mycmkus1bg
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% rtB.ajgpsl4ddz
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% rtB.odlkkgirey
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% rtB.akesstvlt4
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% rtB.ez0vdo0vnv
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% rtB.cm2qntqv5p
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% rtB.fifo30g12w
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% rtB.foo13op1ju
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% rtB.hzo0vy2urp
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% rtB.bhip02e5fq
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% rtB.ir2wrhmfwi
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% rtB.peyixfnwtk
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% rtB.oxl1gbubgw
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% rtB.eclh5z3ew4
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% rtB.ketvnzudn2
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% rtB.lia3hzxqko
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% rtB.pyyanjtp0n
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% rtB.owdhyrttis
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% rtB.h53izkjog2
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% rtB.odp1rox02t
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% rtB.jpajsss3mb
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% rtB.ngngrfhqxt
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% rtB.eemaj3mw1e
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% rtB.gaaymicbge
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% rtB.aubzgcsgjd
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% rtB.eintirb2zo
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% rtB.ioubxgazf2
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 101;
	
	  ;% rtB.hx0qhuwqax
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 102;
	
	  ;% rtB.cwvoke4n3w
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 103;
	
	  ;% rtB.nnypggyeoc
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 104;
	
	  ;% rtB.eqkg2xr2dn
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 105;
	
	  ;% rtB.khvs2osnrm
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 106;
	
	  ;% rtB.f0mglil0tu
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 107;
	
	  ;% rtB.ors3z5ofsx
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 108;
	
	  ;% rtB.ewfilzdy5p
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 109;
	
	  ;% rtB.adv5kzimvn
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 110;
	
	  ;% rtB.jzz0uec2gq
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 111;
	
	  ;% rtB.c12jn5x4j0
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 112;
	
	  ;% rtB.iqjmjwfmns
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 113;
	
	  ;% rtB.afz2yt343k
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 114;
	
	  ;% rtB.nu4szqiw1o
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 115;
	
	  ;% rtB.l5ft2k3pks
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 116;
	
	  ;% rtB.c4o1bl135b
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 117;
	
	  ;% rtB.fsb3gaohdk
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 118;
	
	  ;% rtB.bsh0ijyg1a
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 119;
	
	  ;% rtB.nvjwsszq20
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 120;
	
	  ;% rtB.d3p1u0mvns
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 121;
	
	  ;% rtB.hegnhw35oi
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 122;
	
	  ;% rtB.k44fqt4bzr
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 123;
	
	  ;% rtB.mzrg2hkek3
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 124;
	
	  ;% rtB.irdye5g1gh
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 125;
	
	  ;% rtB.dgotzim4ft
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 126;
	
	  ;% rtB.fkz2npxwns
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 127;
	
	  ;% rtB.h24izcfegy
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 128;
	
	  ;% rtB.p5qpsydo5q
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 129;
	
	  ;% rtB.lm0o0zjx1a
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 130;
	
	  ;% rtB.p4oanyhhie
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 131;
	
	  ;% rtB.p2gjpa4kz5
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 132;
	
	  ;% rtB.j5wjpnvys4
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 133;
	
	  ;% rtB.of10q24r4f
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 134;
	
	  ;% rtB.p5tntlgroy
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 135;
	
	  ;% rtB.b0qoasefti
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 136;
	
	  ;% rtB.gbtvk2ar5t
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 137;
	
	  ;% rtB.dx2og4efcz
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 138;
	
	  ;% rtB.eotgtd3vzy
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 139;
	
	  ;% rtB.nifjgpnast
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 140;
	
	  ;% rtB.bft4uxvudw
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 141;
	
	  ;% rtB.oxpgpvieu5
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 142;
	
	  ;% rtB.e1fwyl5oca
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 143;
	
	  ;% rtB.mlo35lys1s
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 144;
	
	  ;% rtB.div11ckje2
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 145;
	
	  ;% rtB.ppxwyoa2bt
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 146;
	
	  ;% rtB.d14mmlv3sc
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 147;
	
	  ;% rtB.aazow5qyx5
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 148;
	
	  ;% rtB.hdsrwzf2hz
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 149;
	
	  ;% rtB.assjptryio
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 150;
	
	  ;% rtB.bqmgj4wdja
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 151;
	
	  ;% rtB.huti2k1olr
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 152;
	
	  ;% rtB.kpftqud0v4
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 153;
	
	  ;% rtB.bewrfmxe51
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 154;
	
	  ;% rtB.fxe0oi5raa
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 155;
	
	  ;% rtB.b2vno41brr
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 156;
	
	  ;% rtB.pudus0mnkh
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 157;
	
	  ;% rtB.dacgyfnkti
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 158;
	
	  ;% rtB.ksqxzrlacp
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 159;
	
	  ;% rtB.dhutim4yfg
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 160;
	
	  ;% rtB.jy1dhwzsny
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 161;
	
	  ;% rtB.nbmiv4o2qv
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 162;
	
	  ;% rtB.gnam0gpyvd
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 163;
	
	  ;% rtB.mxz0zykzkm
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 164;
	
	  ;% rtB.h2riih5p4x
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 165;
	
	  ;% rtB.ezfjneuvrq
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 166;
	
	  ;% rtB.gzm1otmdfx
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 167;
	
	  ;% rtB.pat0zgdwxm
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 168;
	
	  ;% rtB.fpu4pfoo0u
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 169;
	
	  ;% rtB.jsbnrcbw2w
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 170;
	
	  ;% rtB.a2rcbbb2nd
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 171;
	
	  ;% rtB.auaumgkulf
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 172;
	
	  ;% rtB.ca5bcarb1z
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 173;
	
	  ;% rtB.pmv2c05bpb
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 174;
	
	  ;% rtB.ni04k2if4f
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 175;
	
	  ;% rtB.avovxjitlj
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 176;
	
	  ;% rtB.hl0nz2vhhx
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 177;
	
	  ;% rtB.dopbnbablw
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 178;
	
	  ;% rtB.clp5ptg2aq
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 179;
	
	  ;% rtB.nezd5agty4
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 180;
	
	  ;% rtB.leqschf41u
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 181;
	
	  ;% rtB.ihrr5jombz
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 182;
	
	  ;% rtB.a1cpk0zahd
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 183;
	
	  ;% rtB.iw40x310lw
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 184;
	
	  ;% rtB.csvnqlqe2c
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 185;
	
	  ;% rtB.op4fqs5y2b
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 186;
	
	  ;% rtB.egvgjshusc
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 187;
	
	  ;% rtB.lhy0d514t0
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 188;
	
	  ;% rtB.o1tgujpptc
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 189;
	
	  ;% rtB.ot505slkkd
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 190;
	
	  ;% rtB.f1s21kqqtk
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 191;
	
	  ;% rtB.g5dxxhvf0d
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 192;
	
	  ;% rtB.dohdzn0els
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 193;
	
	  ;% rtB.kdcnvmuwdv
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 194;
	
	  ;% rtB.m4u0zxcmnx
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 195;
	
	  ;% rtB.lfbfrtbus5
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 196;
	
	  ;% rtB.p4sojnckke
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 197;
	
	  ;% rtB.catep12smy
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 198;
	
	  ;% rtB.k0c4i4a3eh
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 199;
	
	  ;% rtB.khzbqlyoyt
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 200;
	
	  ;% rtB.o35dwhcnte
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 201;
	
	  ;% rtB.memjmzawon
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 202;
	
	  ;% rtB.poz0njf0k5
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 203;
	
	  ;% rtB.ph2e13dkoz
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 204;
	
	  ;% rtB.mmzi51sdi4
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 205;
	
	  ;% rtB.bu3dppt1dy
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 206;
	
	  ;% rtB.ihsi5ikxem
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 207;
	
	  ;% rtB.bptwtyixo3
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 208;
	
	  ;% rtB.enljiew2kc
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 209;
	
	  ;% rtB.fisd51h4xh
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 210;
	
	  ;% rtB.jazm3yw1lz
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 211;
	
	  ;% rtB.fu5nvqp5ki
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 212;
	
	  ;% rtB.ib3dugswvz
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 213;
	
	  ;% rtB.gohkxwvfgd
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 214;
	
	  ;% rtB.o00l05l5h5
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 215;
	
	  ;% rtB.imbewi4stk
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 216;
	
	  ;% rtB.hco0swv5mb
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 217;
	
	  ;% rtB.ivmbx4exri
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 218;
	
	  ;% rtB.gbegnosnia
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 219;
	
	  ;% rtB.h3go2eb5uu
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 220;
	
	  ;% rtB.hdmwzbgags
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 221;
	
	  ;% rtB.o0p2ll51dt
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 222;
	
	  ;% rtB.hfprs0psjz
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 223;
	
	  ;% rtB.hywsl3f1uq
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 224;
	
	  ;% rtB.iucqadbg2k
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 225;
	
	  ;% rtB.erjlcjtp4o
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 226;
	
	  ;% rtB.dkle40ro1c
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 227;
	
	  ;% rtB.ihgsjmwc0o
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 228;
	
	  ;% rtB.dhwgonfwmn
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 229;
	
	  ;% rtB.ftodx2djd4
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 230;
	
	  ;% rtB.ihyeehrkag
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 231;
	
	  ;% rtB.i1gcs32wge
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 232;
	
	  ;% rtB.hoerz5xdv5
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 233;
	
	  ;% rtB.cv3osvvlrg
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 234;
	
	  ;% rtB.gqqadn4y2w
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 235;
	
	  ;% rtB.o210behxg1
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 236;
	
	  ;% rtB.hcfgyld3wj
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 237;
	
	  ;% rtB.hmut22z5qh
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 238;
	
	  ;% rtB.oo2wj0jvdb
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 239;
	
	  ;% rtB.ni1kcttkok
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 240;
	
	  ;% rtB.lqnznmftiq
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 241;
	
	  ;% rtB.ktwh1fzhvq
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 242;
	
	  ;% rtB.pmogkogkdf
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 243;
	
	  ;% rtB.kemjegf3wo
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 244;
	
	  ;% rtB.gnnxhf24lb
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 245;
	
	  ;% rtB.fugfqhq0tc
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 246;
	
	  ;% rtB.m3uxwq3r5m
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 247;
	
	  ;% rtB.c1btrhwl4q
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 248;
	
	  ;% rtB.li502xp5qt
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 249;
	
	  ;% rtB.lpc0zrp4fv
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 250;
	
	  ;% rtB.lv5avdu4zp
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 251;
	
	  ;% rtB.ehwkpevl2t
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 252;
	
	  ;% rtB.kjzusoosz1
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 253;
	
	  ;% rtB.nx3vnoo2r0
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 254;
	
	  ;% rtB.dmq1oq0lr3
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 255;
	
	  ;% rtB.cxhhghcvvq
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 256;
	
	  ;% rtB.ey4a5uz5cz
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 257;
	
	  ;% rtB.dppbokyij3
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 258;
	
	  ;% rtB.l3zyv4dhgg
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 259;
	
	  ;% rtB.huaehj053c
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 260;
	
	  ;% rtB.bhkcz3ic0o
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 261;
	
	  ;% rtB.nd01hmisxb
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 262;
	
	  ;% rtB.kjvdspgfqm
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 263;
	
	  ;% rtB.elpxc0kaoh
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 264;
	
	  ;% rtB.jxndwbjtgb
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 265;
	
	  ;% rtB.ajj44xkzb4
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 266;
	
	  ;% rtB.dvvipddzve
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 267;
	
	  ;% rtB.mqne5uhs2r
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 268;
	
	  ;% rtB.b2erwm3zaa
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 269;
	
	  ;% rtB.p5bk0c5qbh
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 270;
	
	  ;% rtB.k4ai1xxr1d
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 271;
	
	  ;% rtB.dyzz0owi01
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 272;
	
	  ;% rtB.nyxhckusoe
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 273;
	
	  ;% rtB.cxloeisrlx
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 274;
	
	  ;% rtB.fk4xevkgeo
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 275;
	
	  ;% rtB.ki1cdbfr44
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 276;
	
	  ;% rtB.eqjo2nizcs
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 277;
	
	  ;% rtB.fba3iic2xf
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 278;
	
	  ;% rtB.eqhzihanz1
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 279;
	
	  ;% rtB.mzef1y2inq
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 280;
	
	  ;% rtB.pfkze4zldv
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 281;
	
	  ;% rtB.oeksgiw32q
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 282;
	
	  ;% rtB.cotqcoyxuq
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 283;
	
	  ;% rtB.aak2xlfzg2
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 284;
	
	  ;% rtB.lewexece42
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 285;
	
	  ;% rtB.dzjno1a2on
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 286;
	
	  ;% rtB.l4rk2cmcdr
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 287;
	
	  ;% rtB.j14ytvzi0h
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 288;
	
	  ;% rtB.eozzahwbfw
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 289;
	
	  ;% rtB.jbs5lruqei
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 290;
	
	  ;% rtB.muwt4hjweu
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 291;
	
	  ;% rtB.mxkquiaqra
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 292;
	
	  ;% rtB.igrtwxdc2h
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 293;
	
	  ;% rtB.bvpv0c32vh
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 294;
	
	  ;% rtB.jmwufnoosm
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 295;
	
	  ;% rtB.hpln2b3wuo
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 296;
	
	  ;% rtB.ltzcpo0hwy
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 297;
	
	  ;% rtB.bn0qdk1o0v
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 298;
	
	  ;% rtB.ehrgc2nkcd
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 299;
	
	  ;% rtB.d04m0qgpku
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 300;
	
	  ;% rtB.nuubxbg4lx
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 301;
	
	  ;% rtB.gebhzzqqrc
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 302;
	
	  ;% rtB.onqwhhqtnq
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 303;
	
	  ;% rtB.flrmowrcgb
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 304;
	
	  ;% rtB.bxeykf3lmp
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 305;
	
	  ;% rtB.dwgmiiuskf
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 306;
	
	  ;% rtB.got041r5yx
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 307;
	
	  ;% rtB.jya4dpmecv
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 308;
	
	  ;% rtB.k3t5arlbzl
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 309;
	
	  ;% rtB.hysbptybxp
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 310;
	
	  ;% rtB.cdxeq3tabw
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 311;
	
	  ;% rtB.fzgl12rcaq
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 312;
	
	  ;% rtB.ftf3u5jby5
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 313;
	
	  ;% rtB.axn3i3rmpl
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 314;
	
	  ;% rtB.cur5w2fqr5
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 315;
	
	  ;% rtB.p0nllhwxyq
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 316;
	
	  ;% rtB.eplzkxfoow
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 317;
	
	  ;% rtB.lufwhlk53w
	  section.data(319).logicalSrcIdx = 318;
	  section.data(319).dtTransOffset = 318;
	
	  ;% rtB.e1yemdo2am
	  section.data(320).logicalSrcIdx = 319;
	  section.data(320).dtTransOffset = 319;
	
	  ;% rtB.jwnrysijt2
	  section.data(321).logicalSrcIdx = 320;
	  section.data(321).dtTransOffset = 320;
	
	  ;% rtB.p3mpeqccbg
	  section.data(322).logicalSrcIdx = 321;
	  section.data(322).dtTransOffset = 321;
	
	  ;% rtB.hdzf4esqkr
	  section.data(323).logicalSrcIdx = 322;
	  section.data(323).dtTransOffset = 322;
	
	  ;% rtB.g4gcmmpsrw
	  section.data(324).logicalSrcIdx = 323;
	  section.data(324).dtTransOffset = 323;
	
	  ;% rtB.hdh1v0e0hz
	  section.data(325).logicalSrcIdx = 324;
	  section.data(325).dtTransOffset = 324;
	
	  ;% rtB.fc035ww10i
	  section.data(326).logicalSrcIdx = 325;
	  section.data(326).dtTransOffset = 325;
	
	  ;% rtB.jag5k22tya
	  section.data(327).logicalSrcIdx = 326;
	  section.data(327).dtTransOffset = 326;
	
	  ;% rtB.n2zjj1zkuh
	  section.data(328).logicalSrcIdx = 327;
	  section.data(328).dtTransOffset = 327;
	
	  ;% rtB.hh5p0emnle
	  section.data(329).logicalSrcIdx = 328;
	  section.data(329).dtTransOffset = 328;
	
	  ;% rtB.g2uumgoeu1
	  section.data(330).logicalSrcIdx = 329;
	  section.data(330).dtTransOffset = 329;
	
	  ;% rtB.c0i4zuvblr
	  section.data(331).logicalSrcIdx = 330;
	  section.data(331).dtTransOffset = 330;
	
	  ;% rtB.lxc1s1ijc2
	  section.data(332).logicalSrcIdx = 331;
	  section.data(332).dtTransOffset = 331;
	
	  ;% rtB.o4pksvc3du
	  section.data(333).logicalSrcIdx = 332;
	  section.data(333).dtTransOffset = 332;
	
	  ;% rtB.p5mmmyyyb0
	  section.data(334).logicalSrcIdx = 333;
	  section.data(334).dtTransOffset = 333;
	
	  ;% rtB.f00vunio45
	  section.data(335).logicalSrcIdx = 334;
	  section.data(335).dtTransOffset = 334;
	
	  ;% rtB.czwkigmd1x
	  section.data(336).logicalSrcIdx = 335;
	  section.data(336).dtTransOffset = 335;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 36;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% rtDW.gfprm23pj3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fqetutrbi5
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.najgra25s3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.lx2q3mhajb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.nflnwukwbw
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.j4zffuf2jc
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.de4qoi0fyx
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.ay4ykamdli
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.jpmhq0y24v
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.eetn342tct
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.ijphmshkuf
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.pdelqeetgv
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.mntyae3rsq
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.bxic41ulzf
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.psneabumzv
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.jhe2qhrig2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.goagc5i3gw
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.ovio5arldz
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.k5o3zhu0wr
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.lioetblzpp
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.dqvle0o2bf
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.kr1ksgnw4x
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.dp5dxb3enf
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.edxttokajv
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.lxx1qcag42
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.f5ldw1c3yp
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.nktwazk3xa
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.piqig1diza
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.hxmdtipph3
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.lcjxt5exz4
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDW.hrm31px4c4
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDW.i31w25jb1l
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDW.itb4eyllvi.modelTStart
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDW.kxpps4lfxs.modelTStart
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDW.mx4clnficd.modelTStart
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDW.j303c3104g.modelTStart
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDW.beayoquk50.modelTStart
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDW.kabx4cifu3.modelTStart
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDW.k0upgp2t11.modelTStart
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDW.pujypq4cfw.modelTStart
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDW.ajc4mvkjxq.LoggedData
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fiob3534rc.LoggedData
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtDW.cby5njrl5e.LoggedData
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 8;
	
	  ;% rtDW.iyh423q2e1.LoggedData
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 12;
	
	  ;% rtDW.iu2ymd21go.LoggedData
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 16;
	
	  ;% rtDW.jlohj4cavb.TUbufferPtrs
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 20;
	
	  ;% rtDW.l1amy53ft4.TUbufferPtrs
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtDW.lyt4jukwzk.LoggedData
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 24;
	
	  ;% rtDW.ovbos1312w.LoggedData
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 25;
	
	  ;% rtDW.omrnl2kvox.TUbufferPtrs
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 26;
	
	  ;% rtDW.b0rupvaogl.TUbufferPtrs
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 28;
	
	  ;% rtDW.glyj0mwrtn.LoggedData
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 30;
	
	  ;% rtDW.leludl1mfe.LoggedData
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 31;
	
	  ;% rtDW.onssg0ise1.TUbufferPtrs
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 32;
	
	  ;% rtDW.h3nqanizu1.TUbufferPtrs
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 34;
	
	  ;% rtDW.gg0snqxwle.LoggedData
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 36;
	
	  ;% rtDW.ddiov3wlge.LoggedData
	  section.data(17).logicalSrcIdx = 56;
	  section.data(17).dtTransOffset = 37;
	
	  ;% rtDW.ip30edpzn0.TUbufferPtrs
	  section.data(18).logicalSrcIdx = 57;
	  section.data(18).dtTransOffset = 38;
	
	  ;% rtDW.nrh2tscls2.TUbufferPtrs
	  section.data(19).logicalSrcIdx = 58;
	  section.data(19).dtTransOffset = 40;
	
	  ;% rtDW.ovc2kc0cmp.LoggedData
	  section.data(20).logicalSrcIdx = 59;
	  section.data(20).dtTransOffset = 42;
	
	  ;% rtDW.gn1lr2gvaw.LoggedData
	  section.data(21).logicalSrcIdx = 60;
	  section.data(21).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtDW.ewcikv2lwd.Tail
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fv0rpgctfs.Tail
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ped5kwc4j1.Tail
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.aem0ceeew5.Tail
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.nogfvg0pt3.Tail
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hs0pmpahcd.Tail
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.pmbhiaijnw.Tail
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.mbyl5zsvhx.Tail
	  section.data(8).logicalSrcIdx = 68;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.gupv3wkm1k
	  section.data(9).logicalSrcIdx = 69;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.oe2kbpvny0
	  section.data(10).logicalSrcIdx = 70;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.ibxrdu4cbs
	  section.data(11).logicalSrcIdx = 71;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.o0angb0u2w
	  section.data(12).logicalSrcIdx = 72;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% rtDW.f3jqreldag
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lkxdv3gp4l
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jqk4qa3xek
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.jcg5lahs5d
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.bugzjuygkx
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.dd30o4lozm
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.ljkqmp5hio
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.mtbsrpr2ww
	  section.data(8).logicalSrcIdx = 80;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.ndweztnvdz
	  section.data(9).logicalSrcIdx = 81;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.jg4lsy03zm
	  section.data(10).logicalSrcIdx = 82;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.lgxvz4jhdw
	  section.data(11).logicalSrcIdx = 83;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.hgbx4f0dqj
	  section.data(12).logicalSrcIdx = 84;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.c12zxjgx2e
	  section.data(13).logicalSrcIdx = 85;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.d3g033qzzb
	  section.data(14).logicalSrcIdx = 86;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.kgnaiafrhn
	  section.data(15).logicalSrcIdx = 87;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.k4echvbh31
	  section.data(16).logicalSrcIdx = 88;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.chwszqir1s.ax0ejju01d
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.n00rwomfjj.ax0ejju01d
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.c51iqw5kno.ax0ejju01d
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.dl522p3brs.ax0ejju01d
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.bj3t3ughuq.ax0ejju01d
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.d2f14sz0ii.ax0ejju01d
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jwm3vbffir.ax0ejju01d
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.levrnc2uqr.ax0ejju01d
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.airq053sdl.ax0ejju01d
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ej5frkoyu2.ax0ejju01d
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fallptwe4n.ax0ejju01d
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jucvauqnq3.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jrnrap5jzh.ax0ejju01d
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.i5omdubmni.ax0ejju01d
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cb0lxisazg.ax0ejju01d
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.a0fdk1tibo.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.nkptjiojzm.ax0ejju01d
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.blc3y3lbsz.ax0ejju01d
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fo1s40z2ng.ax0ejju01d
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.lxwl2pumah.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fibtpbiz5w.ax0ejju01d
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.htznribv1q.ax0ejju01d
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.k1t5j21xa2.ax0ejju01d
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.hzattc0vf2.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.bxy5pgokky.ax0ejju01d
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cical55ljv.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.gciy5nryyx.ax0ejju01d
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.iwvaw3chcg.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ajnw1b3gfz.ax0ejju01d
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.mysqkq0tgk.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fsrrbnl0ono.ax0ejju01d
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.nbpepiek5as.c4bsnmlro2
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4216868706;
  targMap.checksum1 = 730283112;
  targMap.checksum2 = 4144769863;
  targMap.checksum3 = 4039461416;

