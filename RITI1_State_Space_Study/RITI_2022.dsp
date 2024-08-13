// import faust standard library
import("stdfaust.lib");


// INSTRUMENT SPECTRES --------------------------------------
// FFT analysis

// -------------------------------------------------- CELLO C
C_SUL_TASTO_frequencies = (
65.0, 131.0, 196.0, 261.0, 326.0, 392.0, 457.0, 522.0, 588.0, 653.0, 718.0, 784.0, 849.0, 914.0, 979.0, 1045.0, 1110.0, 1175.0, 1241.0, 1306.0, 1371.0, 1502.0, 1567.0, 1632.0, 1698.0, 1763.0, 1828.0, 1894.0, 1959.0, 2024.0, 2089.0, 2351.0
 ) ; 
 
C_SUL_TASTO_amplitudes = (
0.04196492, 0.27707616, 1.0, 0.08153769, 0.05522969, 0.01922137, 0.03436227, 0.03067041, 0.01797695, 0.03381146, 0.0550058, 0.02913938, 0.05834666, 0.03480883, 0.01985851, 0.02222397, 0.02735344, 0.00482074, 0.00496045, 0.00848029, 0.01668042, 0.0121161, 0.04640077, 0.02313585, 0.00729633, 0.00722812, 0.01041008, 0.00722225, 0.00592071, 0.01158114, 0.00443968, 0.00282064
 ) ; 
 
C_SUL_TASTO_bandwidths = (
1.00000000
 ) ; 

C_SUL_PONTE_frequencies = (
65.0, 130.0, 195.0, 261.0, 326.0, 391.0, 456.0, 521.0, 586.0, 651.0, 717.0, 782.0, 847.0, 912.0, 977.0, 1042.0, 1107.0, 1170.0, 1238.0, 1300.0, 1367.0, 1434.0, 1499.0, 1564.0, 1629.0, 1694.0, 1760.0, 1825.0, 1890.0, 1954.0, 2021.0, 2085.0
 ) ; 
 
C_SUL_PONTE_amplitudes = (
0.02789289, 0.40853124, 1.0, 0.11091643, 0.0647856, 0.03734871, 0.02493605, 0.02314501, 0.02637558, 0.03331669, 0.08188277, 0.04299356, 0.06739248, 0.03783816, 0.0274411, 0.04182531, 0.0386263, 0.01525164, 0.00687666, 0.01221123, 0.01760329, 0.00686469, 0.01441863, 0.03875951, 0.04289226, 0.02230978, 0.03048675, 0.01094138, 0.00915901, 0.00736049, 0.00956486, 0.00532164
 ) ; 
 
C_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

C_MOLTO_SUL_PONTE_frequencies = (
65.0, 130.0, 195.0, 261.0, 324.0, 391.0, 456.0, 522.0, 568.0, 652.0, 715.0, 782.0, 849.0, 913.0, 978.0, 1043.0, 1108.0, 1173.0, 1304.0, 1369.0, 1434.0, 1501.0, 1565.0, 1632.0, 1695.0, 1762.0, 1825.0, 1877.0, 1955.0, 2021.0, 2086.0, 2136.0, 2216.0
 ) ; 
 
C_MOLTO_SUL_PONTE_amplitudes = (
0.01789289, 1.0, 0.1119946, 0.37794605, 0.01853937, 0.09701652, 0.01508738, 0.08147287, 0.01527196, 0.13719799, 0.04488286, 0.10778057, 0.03938983, 0.1086438, 0.02285654, 0.18177087, 0.04472455, 0.03171519, 0.04385811, 0.02564654, 0.04654733, 0.02098973, 0.14135472, 0.04765163, 0.05790227, 0.04065074, 0.03339859, 0.02326387, 0.0358107, 0.02291944, 0.03277207, 0.01508144, 0.01629959
 ) ; 
 
C_MOLTO_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

C_ARMONICI_frequencies = (
62.0, 128.0, 192.0, 253.0, 327.0, 383.0, 465.0, 575.0, 653.0, 731.0, 808.0, 879.0, 980.0, 1051.0, 1106.0, 1253.0, 1307.0, 1406.0, 1472.0, 1568.0, 1633.0, 1740.0, 1860.0, 1960.0, 2027.0, 2096.0, 2287.0, 2613.0, 2940.0, 3267.0, 3593.0, 3922.0
 ) ; 
 
C_ARMONICI_amplitudes = (
0.02379753, 0.01588414, 0.0630001, 0.01690107, 1.0, 0.01977984, 0.0071704, 0.02076793, 0.76311832, 0.01959406, 0.00693621, 0.01205804, 0.43136463, 0.00940068, 0.01014689, 0.00820981, 0.18989729, 0.01012334, 0.00511506, 0.02526374, 0.55446251, 0.00962092, 0.00790504, 0.06238205, 0.0096802, 0.00466146, 0.04442261, 0.01876171, 0.01171935, 0.00492013, 0.00646246, 0.00434414
 ) ; 
 
C_ARMONICI_bandwidths = (
1.00000000
 ) ; 


// -------------------------------------------------- CELLO G
G_SUL_TASTO_frequencies = (
98.0, 195.0, 293.0, 391.0, 489.0, 537.0, 587.0, 685.0, 783.0, 880.0, 979.0, 1076.0, 1174.0, 1272.0, 1371.0, 1468.0, 1566.0, 1664.0, 1762.0, 1860.0, 1958.0, 2056.0, 2153.0, 2252.0, 2349.0, 2643.0, 2741.0, 2839.0, 2937.0, 3230.0, 3328.0, 4013.0
 ) ; 
 
G_SUL_TASTO_amplitudes = (
0.75217775, 1.0, 0.09843679, 0.02426847, 0.06051622, 0.00787687, 0.04838698, 0.05785498, 0.0640251, 0.05363475, 0.02121633, 0.03638926, 0.01772408, 0.02102163, 0.00274825, 0.00886369, 0.02193515, 0.01863539, 0.02143791, 0.01670722, 0.01592137, 0.00709897, 0.01305707, 0.00348521, 0.00190274, 0.00161424, 0.00333966, 0.00320751, 0.00126865, 0.00132724, 0.00152525, 0.00097757
 ) ; 
 
G_SUL_TASTO_bandwidths = (
1.00000000
 ) ; 

G_SUL_PONTE_frequencies = (
98.0, 196.0, 294.0, 371.0, 491.0, 537.0, 588.0, 685.0, 785.0, 880.0, 981.0, 1079.0, 1176.0, 1275.0, 1368.0, 1416.0, 1470.0, 1569.0, 1662.0, 1765.0, 1863.0, 1959.0, 2025.0, 2069.0, 2135.0, 2249.0, 2353.0, 2452.0, 2549.0, 2640.0, 2746.0, 2844.0
 ) ; 
 
G_SUL_PONTE_amplitudes = (
0.93944667, 1.0, 0.1397667, 0.04960039, 0.07790099, 0.02185911, 0.0619144, 0.09455926, 0.11242908, 0.10650139, 0.03686391, 0.08468119, 0.04027777, 0.04988492, 0.00878743, 0.00832572, 0.02584302, 0.03396986, 0.03909495, 0.02370068, 0.01383755, 0.00943089, 0.00821213, 0.01066961, 0.00879838, 0.00467986, 0.00689834, 0.00597029, 0.00579739, 0.00418297, 0.00827453, 0.00705785
 ) ; 
 
G_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

G_MOLTO_SUL_PONTE_frequencies = (
97.0, 190.0, 294.0, 370.0, 490.0, 545.0, 588.0, 686.0, 785.0, 882.0, 982.0, 1079.0, 1178.0, 1275.0, 1373.0, 1471.0, 1568.0, 1671.0, 1766.0, 1863.0, 1961.0, 2059.0, 2135.0, 2255.0, 2353.0, 2549.0, 2651.0, 2747.0, 2843.0, 3235.0, 3334.0, 6664.0
 ) ; 
 
G_MOLTO_SUL_PONTE_amplitudes = (
0.41314195, 0.33304011, 0.09897786, 0.09786711, 0.30920571, 0.03242771, 0.24827038, 1.0, 0.24879086, 0.19577422, 0.11964251, 0.29149713, 0.07896685, 0.2476789, 0.0553103, 0.06057399, 0.13858297, 0.01611911, 0.04639251, 0.07277674, 0.18327809, 0.01780529, 0.00905065, 0.02117437, 0.0095725, 0.04107566, 0.01187122, 0.02229674, 0.0160313, 0.01228535, 0.0104387, 0.0054387
 ) ; 
 
G_MOLTO_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

G_ARMONICI_frequencies = (
50.0, 102.0, 191.0, 391.0, 495.0, 538.0, 656.0, 783.0, 889.0, 961.0, 1080.0, 1175.0, 1290.0, 1408.0, 1510.0, 1569.0, 1676.0, 1760.0, 1853.0, 1962.0, 2068.0, 2126.0, 2227.0, 2295.0, 2354.0, 2493.0, 2602.0, 2745.0, 2855.0, 3137.0, 3922.0, 7999.0
 ) ; 
 
G_ARMONICI_amplitudes = (
0.29967682, 0.52334332, 0.559064, 1.0, 0.3884109, 0.15656609, 0.14363522, 0.84879013, 0.17350533, 0.1347252, 0.08320332, 0.68126899, 0.09573852, 0.04995808, 0.0790263, 0.23214791, 0.07300799, 0.02958386, 0.03261651, 0.27091008, 0.05083893, 0.06691769, 0.03115996, 0.01623343, 0.04412083, 0.0099207, 0.0097774, 0.05262677, 0.01634304, 0.0090678, 0.00720456, 0.00639569
 ) ; 
 
G_ARMONICI_bandwidths = (
1.00000000
 ) ; 


// -------------------------------------------------- CELLO D
D_SUL_TASTO_frequencies = (
53.0, 147.0, 203.0, 294.0, 367.0, 441.0, 534.0, 588.0, 735.0, 785.0, 882.0, 961.0, 1028.0, 1078.0, 1175.0, 1269.0, 1323.0, 1470.0, 1617.0, 1764.0, 1855.0, 1910.0, 2054.0, 2204.0, 2273.0, 2351.0, 2498.0, 2645.0, 2792.0, 3233.0, 3380.0, 3527.0
 ) ; 
 
D_SUL_TASTO_amplitudes = (
0.07116083, 1.0, 0.0405712, 0.49828005, 0.02470587, 0.25042786, 0.0250452, 0.09954785, 0.54357606, 0.01573797, 0.2722688, 0.01228042, 0.14442907, 0.01626654, 0.28175268, 0.02115358, 0.07170723, 0.06191843, 0.07354127, 0.05126037, 0.01093969, 0.0343155, 0.06985491, 0.09585942, 0.00656447, 0.01233555, 0.01134687, 0.01055565, 0.03127152, 0.01587526, 0.00962998, 0.0068168
 ) ; 
 
D_SUL_TASTO_bandwidths = (
1.00000000
 ) ; 

D_SUL_PONTE_frequencies = (
47.0, 147.0, 295.0, 376.0, 442.0, 589.0, 737.0, 884.0, 1032.0, 1179.0, 1326.0, 1474.0, 1621.0, 1768.0, 1916.0, 2063.0, 2211.0, 2358.0, 2506.0, 2653.0, 2800.0, 2947.0, 3095.0, 3242.0, 3390.0, 3537.0, 3832.0, 4126.0, 4716.0, 8695.0, 8842.0, 8990.0
 ) ; 
 
D_SUL_PONTE_amplitudes = (
0.0115988, 0.79435758, 1.0, 0.00761094, 0.31147711, 0.27645337, 0.70041476, 0.37004342, 0.22757333, 0.26280688, 0.0140129, 0.26240869, 0.22235847, 0.09641164, 0.06606946, 0.17807532, 0.08549717, 0.0395032, 0.00685839, 0.03022879, 0.03570775, 0.00762574, 0.00934675, 0.00905542, 0.01589669, 0.00390371, 0.01159427, 0.00429153, 0.00508935, 0.00393937, 0.00423055, 0.00489773
 ) ; 
 
D_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

D_MOLTO_SUL_PONTE_frequencies = (
50.0, 120.0, 193.0, 308.0, 367.0, 453.0, 537.0, 589.0, 736.0, 828.0, 880.0, 964.0, 1031.0, 1101.0, 1179.0, 1275.0, 1330.0, 1408.0, 1480.0, 1630.0, 1727.0, 1782.0, 1933.0, 2085.0, 2233.0, 2402.0, 2567.0, 2658.0, 2725.0, 3385.0, 3564.0, 3716.0
 ) ; 
 
D_MOLTO_SUL_PONTE_amplitudes = (
0.12016983, 0.20445953, 0.36800338, 0.15692499, 0.30131985, 0.14972588, 0.18533416, 0.33731543, 0.72214925, 0.05300139, 0.42079979, 0.12813918, 0.30809514, 0.09815371, 0.57583112, 0.04054637, 0.23351324, 0.0829156, 0.97109771, 1.0, 0.05439881, 0.61768199, 0.46537996, 0.65365303, 0.2683161, 0.195627, 0.09141798, 0.06337808, 0.21253215, 0.04839137, 0.07402531, 0.14828266
 ) ; 
 
D_MOLTO_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

D_ARMONICI_frequencies = (
50.0, 120.0, 189.0, 301.0, 363.0, 588.0, 711.0, 775.0, 876.0, 937.0, 1009.0, 1096.0, 1177.0, 1308.0, 1414.0, 1506.0, 1572.0, 1684.0, 1768.0, 1870.0, 1929.0, 2068.0, 2162.0, 2277.0, 2349.0, 2458.0, 2580.0, 2780.0, 2940.0, 3199.0, 3330.0, 4116.0
 ) ; 
 
D_ARMONICI_amplitudes = (
0.08798947, 0.06955063, 0.38684497, 0.12097697, 0.0666715, 1.0, 0.05412838, 0.07071769, 0.0406236, 0.0585358, 0.05028837, 0.17782794, 0.58121312, 0.01898218, 0.04289775, 0.0657497, 0.07530507, 0.04046669, 0.07199584, 0.01676172, 0.02490302, 0.02432096, 0.02480079, 0.02332054, 0.05601889, 0.01049962, 0.00898637, 0.03078073, 0.02698139, 0.00997946, 0.01003087, 0.01249989
 ) ; 
 
D_ARMONICI_bandwidths = (
1.00000000
 ) ; 


// -------------------------------------------------- CELLO A
A_SUL_TASTO_frequencies = (
50.0, 130.0, 220.0, 309.0, 368.0, 439.0, 538.0, 659.0, 879.0, 1099.0, 1319.0, 1539.0, 1759.0, 1978.0, 2198.0, 2418.0, 2638.0, 2858.0, 3078.0, 3298.0, 3517.0, 3737.0, 3957.0, 4177.0, 4617.0, 5056.0, 5496.0, 5717.0, 7035.0, 7255.0, 8574.0, 9672.0
 ) ; 
 
A_SUL_TASTO_amplitudes = (
0.01835863, 0.01216278, 1.0, 0.00749257, 0.01035828, 0.6674602, 0.00707754, 0.62411215, 0.4053105, 0.64427134, 0.27821024, 0.08982961, 0.07338235, 0.03442368, 0.22375855, 0.02409027, 0.04759307, 0.03888326, 0.01222045, 0.03283333, 0.02061391, 0.02601317, 0.01631748, 0.01776269, 0.00854136, 0.01528356, 0.01369543, 0.00841917, 0.02237106, 0.00969712, 0.00986048, 0.01255551
 ) ; 
 
A_SUL_TASTO_bandwidths = (
1.00000000
 ) ; 

A_SUL_PONTE_frequencies = (
50.0, 130.0, 220.0, 309.0, 370.0, 440.0, 571.0, 660.0, 880.0, 962.0, 1099.0, 1319.0, 1472.0, 1539.0, 1610.0, 1760.0, 1979.0, 2199.0, 2289.0, 2419.0, 2639.0, 2859.0, 3079.0, 3298.0, 3518.0, 3738.0, 3958.0, 4178.0, 4398.0, 4618.0, 5937.0, 6157.0, 7037.0, 7696.0
 ) ; 
 
A_SUL_PONTE_amplitudes = (
0.01835863, 0.01595528, 1.0, 0.00749257, 0.01473354, 0.87218321, 0.00859515, 0.58950176, 0.38136923, 0.0123053, 0.58324971, 0.37238753, 0.00848152, 0.18288659, 0.01062739, 0.0110874, 0.05359905, 0.31640501, 0.01081347, 0.02695659, 0.06988175, 0.0487292, 0.02884024, 0.05809226, 0.03553339, 0.04916007, 0.02046966, 0.02435397, 0.00808617, 0.0085891, 0.00905874, 0.01194446, 0.02025366, 0.00864089
 ) ; 
 
A_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

A_MOLTO_SUL_PONTE_frequencies = (
50.0, 97.0, 191.0, 309.0, 365.0, 440.0, 541.0, 658.0, 764.0, 878.0, 960.0, 1010.0, 1098.0, 1236.0, 1316.0, 1431.0, 1471.0, 1534.0, 1759.0, 1977.0, 2199.0, 2417.0, 2639.0, 2857.0, 3079.0, 3297.0, 3517.0, 3736.0, 4179.0, 5718.0, 7260.0, 7699.0, 8358.0
 ) ; 
 
A_MOLTO_SUL_PONTE_amplitudes = (
0.09118761, 0.12160486, 0.37748318, 0.00749257, 0.13470854, 0.22464179, 0.07338048, 0.53291657, 0.03839275, 0.35695539, 0.05320811, 0.05098461, 1.0, 0.0278835, 0.1524945, 0.02130052, 0.03015198, 0.0465949, 0.08738714, 0.15106893, 0.56470169, 0.14170238, 0.1250138, 0.08395657, 0.0551964, 0.06252154, 0.11631001, 0.03080954, 0.02444248, 0.02256155, 0.02680212, 0.04103985, 0.02178977
 ) ; 
 
A_MOLTO_SUL_PONTE_bandwidths = (
1.00000000
 ) ; 

A_ARMONICI_frequencies = (
62.0, 130.0, 191.0, 261.0, 311.0, 370.0, 457.0, 537.0, 705.0, 878.0, 972.0, 1117.0, 1169.0, 1247.0, 1472.0, 1697.0, 1755.0, 1983.0, 2050.0, 2287.0, 2381.0, 2546.0, 2632.0, 2813.0, 3185.0, 3247.0, 3517.0, 4395.0, 6150.0, 7892.0, 8787.0, 9665.0
 ) ; 
 
A_ARMONICI_amplitudes = (
0.0518624, 0.01107689, 0.04390014, 0.01010253, 0.0061377, 0.02792264, 0.00731042, 0.00808291, 0.0146077, 1.0, 0.0069374, 0.00814141, 0.00537457, 0.00460423, 0.0111435, 0.02712111, 0.178429, 0.00467003, 0.0076334, 0.00658081, 0.00390276, 0.00570306, 0.04632687, 0.00751121, 0.00556629, 0.00511733, 0.01623212, 0.01861312, 0.01242462, 0.0044044, 0.00456787, 0.00629657
 ) ; 
 
A_ARMONICI_bandwidths = (
1.00000000
 ) ; 


// INSTRUMENT SPECTRES --------------------------------------
// index of the lists

FreqsListCH01(index) =  ba.take(index,  C_SUL_TASTO_frequencies ) ;
AmplsListCH01(index) =  ba.take(index,  C_SUL_TASTO_amplitudes  ) ;
BandsListCH01(index) =  ba.take(1,      C_SUL_TASTO_bandwidths  ) ;

FreqsListCH02(index) =  ba.take(index,  C_SUL_PONTE_frequencies ) ;
AmplsListCH02(index) =  ba.take(index,  C_SUL_PONTE_amplitudes  ) ;
BandsListCH02(index) =  ba.take(1,      C_SUL_PONTE_bandwidths  ) ;

FreqsListCH03(index) =  ba.take(index,  C_MOLTO_SUL_PONTE_frequencies ) ;
AmplsListCH03(index) =  ba.take(index,  C_MOLTO_SUL_PONTE_amplitudes  ) ;
BandsListCH03(index) =  ba.take(1,      C_MOLTO_SUL_PONTE_bandwidths  ) ;

FreqsListCH04(index) =  ba.take(index,  C_ARMONICI_frequencies ) ;
AmplsListCH04(index) =  ba.take(index,  C_ARMONICI_amplitudes  ) ;
BandsListCH04(index) =  ba.take(1,      C_ARMONICI_bandwidths  ) ;

FreqsListCH05(index) =  ba.take(index,  G_SUL_TASTO_frequencies ) ;
AmplsListCH05(index) =  ba.take(index,  G_SUL_TASTO_amplitudes  ) ;
BandsListCH05(index) =  ba.take(1,      G_SUL_TASTO_bandwidths  ) ;

FreqsListCH06(index) =  ba.take(index,  G_SUL_PONTE_frequencies ) ;
AmplsListCH06(index) =  ba.take(index,  G_SUL_PONTE_amplitudes  ) ;
BandsListCH06(index) =  ba.take(1,      G_SUL_PONTE_bandwidths  ) ;

FreqsListCH07(index) =  ba.take(index,  G_MOLTO_SUL_PONTE_frequencies ) ;
AmplsListCH07(index) =  ba.take(index,  G_MOLTO_SUL_PONTE_amplitudes  ) ;
BandsListCH07(index) =  ba.take(1,      G_MOLTO_SUL_PONTE_bandwidths  ) ;

FreqsListCH08(index) =  ba.take(index,  G_ARMONICI_frequencies ) ;
AmplsListCH08(index) =  ba.take(index,  G_ARMONICI_amplitudes  ) ;
BandsListCH08(index) =  ba.take(1,      G_ARMONICI_bandwidths  ) ;

FreqsListCH09(index) =  ba.take(index,  D_SUL_TASTO_frequencies ) ;
AmplsListCH09(index) =  ba.take(index,  D_SUL_TASTO_amplitudes  ) ;
BandsListCH09(index) =  ba.take(1,      D_SUL_TASTO_bandwidths  ) ;

FreqsListCH10(index) =  ba.take(index,  D_SUL_PONTE_frequencies ) ;
AmplsListCH10(index) =  ba.take(index,  D_SUL_PONTE_amplitudes  ) ;
BandsListCH10(index) =  ba.take(1,      D_SUL_PONTE_bandwidths  ) ;

FreqsListCH11(index) =  ba.take(index,  D_MOLTO_SUL_PONTE_frequencies ) ;
AmplsListCH11(index) =  ba.take(index,  D_MOLTO_SUL_PONTE_amplitudes  ) ;
BandsListCH11(index) =  ba.take(1,      D_MOLTO_SUL_PONTE_bandwidths  ) ;

FreqsListCH12(index) =  ba.take(index,  D_ARMONICI_frequencies ) ;
AmplsListCH12(index) =  ba.take(index,  D_ARMONICI_amplitudes  ) ;
BandsListCH12(index) =  ba.take(1,      D_ARMONICI_bandwidths  ) ;

FreqsListCH13(index) =  ba.take(index,  A_SUL_TASTO_frequencies ) ;
AmplsListCH13(index) =  ba.take(index,  A_SUL_TASTO_amplitudes  ) ;
BandsListCH13(index) =  ba.take(1,      A_SUL_TASTO_bandwidths  ) ;

FreqsListCH14(index) =  ba.take(index,  A_SUL_PONTE_frequencies ) ;
AmplsListCH14(index) =  ba.take(index,  A_SUL_PONTE_amplitudes  ) ;
BandsListCH14(index) =  ba.take(1,      A_SUL_PONTE_bandwidths  ) ;

FreqsListCH15(index) =  ba.take(index,  A_MOLTO_SUL_PONTE_frequencies ) ;
AmplsListCH15(index) =  ba.take(index,  A_MOLTO_SUL_PONTE_amplitudes  ) ;
BandsListCH15(index) =  ba.take(1,      A_MOLTO_SUL_PONTE_bandwidths  ) ;

FreqsListCH16(index) =  ba.take(index,  A_ARMONICI_frequencies ) ;
AmplsListCH16(index) =  ba.take(index,  A_ARMONICI_amplitudes  ) ;
BandsListCH16(index) =  ba.take(1,      A_ARMONICI_bandwidths  ) ;

// lists interpolations
FrequenciesListSum(index, Sel) =   
                            (FreqsListCH01(index) * (Sel == 1)) + 
                            (FreqsListCH02(index) * (Sel == 2)) +
                            (FreqsListCH03(index) * (Sel == 3)) +
                            (FreqsListCH04(index) * (Sel == 4)) ;
AmplitudesListSum(index, Sel) =    
                            (AmplsListCH01(index)  * (Sel == 1)) + 
                            (AmplsListCH02(index)  * (Sel == 2)) + 
                            (AmplsListCH03(index)  * (Sel == 3)) + 
                            (AmplsListCH04(index)  * (Sel == 4)) ;
BandwidthsListSum(index, Sel) =    
                            (BandsListCH01(index)  * (Sel == 1)) + 
                            (BandsListCH02(index)  * (Sel == 2)) + 
                            (BandsListCH03(index)  * (Sel == 3)) + 
                            (BandsListCH04(index)  * (Sel == 4)) ;


// ChngList = nentry("Change List", 1, 1, 4, 1);
// process = par(i, 10, FrequenciesListG((i + 1), ChngList), AmplitudesListG((i + 1), ChngList), BandwidthsListG((i + 1), ChngList));

// linear interpolation
linInterpolate(x0, x1, delta) = x0 + delta * (x1-x0);
siglinInterpol(order, x) = x : seq(r, order, interpolate)
with{
    interpolate(y) = y + .5 * (y' - y);
};

// bilinear interpolation
bilinInterpolate(x0, x1, x0b, x1b, dt1, dt2) = 
    linInterpolate(
        linInterpolate(x0, x1, dt1), 
        linInterpolate(x0b, x1b, dt1),
        dt2)
    with{
        linInterpolate(x0, x1, delta) = x0 + delta * (x1-x0);
    };

// lists interpolations
FrequenciesListinterpolate(index, Sel1, Sel2, Sel3, Sel4, dt1, dt2) = 
    bilinInterpolate(
        FreqsListCH01(index), 
        FreqsListCH02(index), 
        FreqsListCH03(index), 
        FreqsListCH04(index), 
        dt1, dt2);
AmplitudesListinterpolate(index, Sel1, Sel2, Sel3, Sel4, dt1, dt2) = 
    bilinInterpolate(
        AmplsListCH01(index), 
        AmplsListCH02(index), 
        AmplsListCH03(index), 
        AmplsListCH04(index), 
        dt1, dt2);
BandwidthsListinterpolate(index, Sel1, Sel2, Sel3, Sel4, dt1, dt2) = 
    bilinInterpolate(
        BandsListCH01(index), 
        BandsListCH02(index), 
        BandsListCH03(index), 
        BandsListCH04(index), 
        dt1, dt2);

//---------------------------------------------------------------- FUNCTIONS ---
// Give a distance in meters - Delay time in samples in output
meterstoSamps(Meters) =  ((1000 / 343.1) * Meters) * (ma.SR / 1000);
ms2samp(t) = (t/1000) * ma.SR;
sec2samp(t) = t * ma.SR;

limit(maxl,minl,x) = x : max(minl, min(maxl)); 
XYZinspect(i, x, y, z) = hgroup("NetworkVoice_%i[2]", (Xvmeter((i+1), 0, 1000, x), Yvmeter((i+1), 0, 1000, y), Zvmeter((i+1), 0, 1000, z)));
Xvmeter(i, minx, maxx, x) = attach(x, x : peakenvelope(10) : vbargraph("X_%i[2] [style:numerical]", minx, maxx));
Yvmeter(i, minx, maxx, y) = attach(y, y : peakenvelope(10) : vbargraph("Y_%i[2] [style:numerical]", minx, maxx));
Zvmeter(i, minx, maxx, z) = attach(z, z : peakenvelope(10) : vbargraph("Z_%i[2] [style:numerical]", minx, maxx));
Vmeter(i, minx, maxx, x) = attach(x, x : peakenvelope(10) : vbargraph("%i[2] [style:numerical]", minx, maxx));
Hmeter(i, minx, maxx, x) = attach(x, x : peakenvelope(10) : hbargraph("%i[2] [style:numerical]", minx, maxx));

//------------------------------------------ CHAOTIC EQUATIONS CONSTRICTIONS ---
saturator(lim, x) = lim * ma.tanh(x / (max(lim, ma.EPSILON)));

dcblocker(zero, pole, x) = x : dcblockerout
    with{
        onezero =  _ <: _,mem : _,*(zero) : -;
        onepole = + ~ * (pole);
        dcblockerout = _ : onezero : onepole;
    };

timeVaryingDelay(delTime, fbGain, x) = loop ~ _ : mem
with {  
    loop(fb) = (fb * fbGain + x) : 
        de.sdelay( ba.sec2samp(DelSecondsMax), 
        1024, 
        ba.sec2samp(delTime)-1 );
    };

//------------------------------------------------------------------ FILTERS ---
// Zavalishin's SVF BP FILTER
// optimized BP from the TPT version of the SVF Filter by Vadim Zavalishin
// reference : (by Will Pirkle)
// http://www.willpirkle.com/Downloads/AN-4VirtualAnalogFilters.2.0.pdf
BPSVF(glin, bw, cf, x) = loop ~ si.bus(2) : (! , ! , _)
    with {
        g = tan(cf * ma.PI * (1.0/ma.SR));
        Q = cf / max(ma.EPSILON, bw);
        R = 1.0 / (Q + Q);
        G = 1.0 / (1.0 + 2.0 * R * g + g * g);
        loop(s1, s2) = u1 , u2 , bp * glin
            with {
                bp = (g * (x - s2) + s1) * G;
                bp2 = bp + bp;
                v2 = bp2 * g;
                u1 = bp2 - s1;
                u2 = v2 + s2;
            };
    };
// Zavalishin's Onepole TPT Filter
// reference : same of BPSVF
onePoleTPT(cf, x) = loop ~ _ : ! , si.bus(3) // Outs: lp , hp , ap
with {
    g = tan(cf * ma.PI * (1.0/ma.SR));
    G = g / (1.0 + g);
    loop(s) = u , lp , hp , ap
    with {
        v = (x - s) * G; u = v + lp; lp = v + s; hp = x - lp; ap = lp - hp;
    };
};
// Lowpass TPT
LPTPT(cf, x) = onePoleTPT(cf, x) : (_ , ! , !);
// Highpass TPT
HPTPT(cf, x) = onePoleTPT(cf, x) : (! , _ , !);

// Spectre BP Filter Banks
BandpassFiltersBank(bypassFilter, directFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, chngList1, chngList2, chngList3, chngList4, x) = x <: 
    par(i, filterPartials, 
        seq(r, filterOrder, 
            BPSVF(
                AmplitudesListinterpolate(  (i + 1), chngList1, chngList2, chngList3, chngList4, interpolation1, interpolation2) * globalAmps, 
                BandwidthsListinterpolate(  (i + 1), chngList1, chngList2, chngList3, chngList4, interpolation1, interpolation2) * globalBW, 
                FrequenciesListinterpolate( (i + 1), chngList1, chngList2, chngList3, chngList4, interpolation1, interpolation2) * globalFreq
            ) 
        )
    ):> (+ / filterPartials) * directFilter + (x * bypassFilter);

onepoletau(tau, x) = fb ~ _ 
with {  
    fb(y) = (1.0 - s) * x + s * y; 
    s = exp(-1.0/(tau * ma.SR));
    //   tau = desired smoothing time constant in seconds
    };
    
//---------------------------------------------------------------- ANALIZERS ---
peakHolder(holdTime, x) = loop ~ si.bus(2) : ! , _
with {
    loop(timerState, outState) = timer , output
    with {
        isNewPeak = abs(x) >= outState;
        isTimeOut = timerState >= (holdTime * ma.SR - 1);
        bypass = isNewPeak | isTimeOut;
        timer = ba.if(bypass, 0, timerState + 1);
        output = ba.if(bypass, abs(x), outState);
    };
};

// RMS with indipendent attack and release time:
// reference:
// Udo Zölzer - Digital Audio Signal Processing Second Edition
// reference :
// https://fmipa.umri.ac.id/wp-content/uploads/2016/03/
// Udo-Zolzer-digital-audio-signal-processing.9780470997857.40435.pdf
RMS(att,rel,x) = loop ~ _ : sqrt
with {
    loop(y) = (1.0 - coeff) * x * x + coeff * y
    with {
        attCoeff = exp(-2.0 * ma.PI * (1.0/ma.SR) / att);
        relCoeff = exp(-2.0 * ma.PI * (1.0/ma.SR) / rel);
        coeff = ba.if(abs(x) > y, attCoeff, relCoeff);
    };
};

// Moving Average RMS
movingAverage(seconds, x) = x - (x @ N) : fi.pole(1.0) / N
with {
N = seconds * ma.SR;
};
RMSRectangular(seconds, x) = sqrt(max(0, movingAverage(seconds, x * x)));

// Peak Envelope (envelope follower)
// reference :
// https://www.dariosanfilippo.com/blog/2017/
// lookahead-limiting-in-pure-data/
// reference :
// https://www.cs.princeton.edu/courses/archive/spr05/cos579/DSP/DSP.html
peakenvelope(t,x) = abs(x) <: loop ~ _ * rt60(t)
with{
    loop(y,z) = ( (y,z) : max);
    rt60(t) = 0.001^((1/ma.SR)/t);
};

// peak-hold module with an exponential decay curve
peakHoldwDecay(holdSeconds, frequencyCut, decayT60, x) = x : 
    peakHolder(holdSeconds) : LPTPT(frequencyCut) : peakenvelope(decayT60);

//------------------------------------------------------- LOOKAHEAD LIMITERS ---
// reference :
// https://www.dariosanfilippo.com/blog/2017/
// lookahead-limiting-in-pure-data/
// reference :
// https://users.iem.at/zmoelnig/publications/limiter/
// Peak normalization
// reference :
// https://www.hackaudio.com/digital-signal-processing/amplitude/peak-normalization/

normalization(treshold, x) = treshold / ( x : peakHoldwDecay(.1, 500, 10) ) *
    x @ (( 2/1000 ) * ma.SR);

limitation(threshold, x) = ( x : peakHoldwDecay(.1, 500, 10) ) : 
    ( threshold / max(ma.EPSILON, _) : min(1.0) ) *
        ( x @ (ms2samp(1)));

//------------------------------------------------------------- NONLINEARITY ---


nonLinearity(exponent, refPeriod, y) = y : lowFreqNoise <: (nonlinearsig(exponent, ma.tanh(_ * normRMS)))
with{
    lowFreqNoise(x) = x : seq(i, 4, LPTPT(1.0 / refPeriod));
    noiseRMS(x) = x * x : LPTPT(1.0 / (10.0 * refPeriod)) : sqrt;
    normRMS(x) = 1.0 / max(ma.EPSILON, noiseRMS(x));
    nonlinearsig(exponent, x) = ma.signum(x) * pow(abs(x), exponent);
};


// SYSTEM INTERFACE ----------------------------------------
TGroup(x) = tgroup("Main", x);
    MixerGroup(x) = hgroup("Mixer", x);
        FiltersGroup(x) = hgroup("Bandpass Filters Bank", x);
            TFreqsGroup(x) = tgroup("Bank Voices", x);
            FreqsGroup(i, x) = hgroup("Voice_%i", x);
        FDNGroup(x) = hgroup("Feedback Delay Network", x);
            INDelayGroup(x) = hgroup("Input Delays", x);
            OUTDelayGroup(x) = hgroup("Output Delays", x);
            GainDelayGroup(x) = hgroup("Gains Network", x);
            TDelayGroup(x) = tgroup("Delay Times", x);
        InsOutsGroup(x) = hgroup("Inputs and Outputs", x);
        LorenzFuncGroup(x) = hgroup("Lorenz Equation Parameters", x);
    InspectorsGroup(x) = vgroup("Inspectors", x);

// SYSTEM VARIABLES ----------------------------------------
DelSecondsMax = 12;
SystemSpaceVarOUT = 2.8713;
SystemSpaceVarIN =  2.3132;
BPFOrder = 1;
BPFilters = 32;
NetworkVoices = 4;
InitDCBlockzero = 1;
InitDCBlockpole = 0.995;
InitX0 = 1.2;
InitY0 = 1.3;
InitZ0 = 1.6;

Dtf = TGroup((ba.db2linear(MixerGroup(LorenzFuncGroup(vslider("Dt [unit:dB]", 0, -60, 60, .001)))))) : onepoletau(2);
Sigmaf = TGroup((MixerGroup(LorenzFuncGroup(vslider("Sigma", 10, 1, 19, .001))))) : onepoletau(2);
Rhof = TGroup((MixerGroup(LorenzFuncGroup(vslider("Rho", 3.518, 2.8, 53.2, .001))))) : onepoletau(2);
Betaf = TGroup((MixerGroup(LorenzFuncGroup(vslider("Beta", 1.073, 0.2666, 5.066, .001))))) : onepoletau(2);
BPFilterBypassf = TGroup((MixerGroup(FiltersGroup(vslider("BP Bypass", 0, 0, 1, .001))))) : onepoletau(2);
BPFilterDirectf = TGroup((MixerGroup(FiltersGroup(vslider("BP Signal", 1, 0, 1, .001))))) : onepoletau(2);
GlobalBPFrequenciesf(i) = TGroup((16 ^ MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, vslider("Frequency [unit:Hz]", 0, -1, 1, .001))))))) : onepoletau(2);
GlobalBPBWf = TGroup((MixerGroup(FiltersGroup(vslider("Bandwidth [unit:Hz]", 1, 1, 100, .001))))) : onepoletau(2);
ChngList1f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 1", 1, 1, 4, 1)))))));
ChngList2f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 2", 2, 1, 4, 1)))))));
ChngList3f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 3", 3, 1, 4, 1)))))));
ChngList4f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 4", 4, 1, 4, 1)))))));
Interpolations1f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, vslider("Interpolations A", 0, 0, 1, .001))))))) : onepoletau(2);
Interpolations2f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, vslider("Interpolations B", 0, 0, 1, .001))))))) : onepoletau(2);
Saturationf = TGroup((MixerGroup(LorenzFuncGroup(vslider("TanH [unit:TanH]", 50, 1, 100, .001))))) : onepoletau(2);
LorenzFeedbackf = TGroup(MixerGroup(LorenzFuncGroup(vslider("Lorenz FB", 1, 0, 1, .001)))) : onepoletau(2);  
OutputGainf = TGroup(((ba.db2linear(MixerGroup(InsOutsGroup(vslider("Master [unit:dB]", -80, -80, 0, .001))))) : \(x).( (x > ba.db2linear(-80)) * x ))) : onepoletau(2);
ExternalInputGainf = TGroup(((ba.db2linear(MixerGroup(InsOutsGroup(vslider("Externals [unit:dB]", -80, -80, 80, .001))))) : 
    \(x).( (x > ba.db2linear(-80)) * x ))) : onepoletau(2);


// MODIFIED LORENZ SYSTEM ----------------------------------------

ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, bypassFilter, directFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, changeList1, changeList2, changeList3, changeList4, saturation, dcBlockzero, dcBlockpole, internalFeedback, i, externalInput) = 
    (
        (
        par(i, 3, _ * internalFeedback) : 
        TGroup(InspectorsGroup(hgroup("Lorenz Feedback", XYZinspect(i)))) : LorenzSystemEquations
        ) : 
            par(i, 3, _ : dcblocker(dcBlockzero, dcBlockpole)) : 
            TGroup(InspectorsGroup(hgroup("DC Blocker", XYZinspect(i)))) : 
                par(i, 3, _ : saturator(saturation)) : 
                TGroup(InspectorsGroup(hgroup("Hyperbolic Tangent", XYZinspect(i)))) : 
                    par(i, 3, _ : BandpassFiltersBank(bypassFilter, directFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, changeList1, changeList2, changeList3, changeList4)) : 
                    TGroup(InspectorsGroup(hgroup("Bandpass Filters", XYZinspect(i))))
    ) ~ si.bus(3) : 
        par(i, 3, / (max(saturation, ma.EPSILON))) :> _ / 3
    with {
        x_init = x0-x0';    y_init = y0-y0';    z_init = z0-z0';
        LorenzSystemEquations(x, y, z) = 
            ((((x + externalInput) + sigma * (y - x) * dt + x_init))), 
            ((((y + externalInput) + (rho * x - x * z - y) * dt + y_init))),  
            ((((z + externalInput) + (x * y - beta * z) * dt + z_init)));
    };


// GLOBAL SYSTEM NETWORK ----------------------------------------

GlobalSystemNetwork(Mic1, Mic2, Mic3, Mic4) = 
    (NetworkLoop ~ _ : (si.block(1), si.bus(NetworkVoices))) : 
            par(i, NetworkVoices, _ : dcblocker(InitDCBlockzero, InitDCBlockpole) : normalization(1)) : 
                par(i, NetworkVoices, _ * OutputGainf )
    with{    
        NetworkLoop(networkFeedback) =  par(i,  NetworkVoices, 
            (networkFeedback * (TGroup(MixerGroup(FDNGroup(TDelayGroup(GainDelayGroup(vslider("Voice_%i+1[2]", 1, 0, 1, .001))))))) : 
                (timeVaryingDelay(TGroup(MixerGroup(FDNGroup(TDelayGroup(INDelayGroup(vslider("Voice_%i+1[2]  [unit:Sec]", 
                (SystemSpaceVarIN * (NetworkVoices - i)), .001, DelSecondsMax, .001)))))), 0) + (((Mic1,Mic2,Mic3,Mic4) :> _ / 4) * ExternalInputGainf)) : 
                    ModifiedLorenzSystem(InitX0, InitY0, InitZ0, Dtf, Betaf, Rhof, Sigmaf, BPFilterBypassf, BPFilterDirectf, BPFilters, BPFOrder, 
                    GlobalBPFrequenciesf(i), 1, GlobalBPBWf, Interpolations1f(i), Interpolations2f(i), ChngList1f(i), ChngList2f(i), ChngList3f(i), ChngList4f(i), Saturationf, InitDCBlockzero, InitDCBlockpole, LorenzFeedbackf, i)
                            )
                        ) <: 
                        (par( i, NetworkVoices, _ : timeVaryingDelay(TGroup(MixerGroup(FDNGroup(TDelayGroup(OUTDelayGroup(vslider("Voice_%i+1[2]  [unit:Sec]",  SystemSpaceVarOUT * (i + 1), .001, DelSecondsMax, .001)))))) , 0)) :> +/NetworkVoices), (si.bus(NetworkVoices));
    };    


process = si.bus(8) :> si.bus(4) : GlobalSystemNetwork;