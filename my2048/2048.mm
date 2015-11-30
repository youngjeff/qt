<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node COLOR="#009999" CREATED="1448801116436" ID="ID_81351074" MODIFIED="1448801661348" TEXT="2048">
<node COLOR="#0033ff" CREATED="1448801160549" ID="ID_1530828720" MODIFIED="1448801627204" POSITION="right" STYLE="bubble" TEXT="&#x7f16;&#x8f91;&#x754c;&#x9762;">
<node CREATED="1448801305682" ID="ID_49095670" MODIFIED="1448801689624" TEXT="4 * 4">
<node CREATED="1448801360643" ID="ID_1535901900" MODIFIED="1448801627206" TEXT="bkclolor"/>
<node CREATED="1448801382251" ID="ID_619518370" MODIFIED="1448801627206" TEXT="ftcolor"/>
</node>
</node>
<node CREATED="1448801446644" ID="ID_789534327" MODIFIED="1448802405615" POSITION="right" STYLE="bubble" TEXT="resizeEvent">
<node CREATED="1448801504094" ID="ID_1249767472" MODIFIED="1448802405616" STYLE="bubble" TEXT="&#x63a7;&#x5236;&#x754c;&#x9762;&#x5927;&#x5c0f;&#xff0c;&#x9002;&#x5e94;&#x5404;&#x79cd;&#x5c4f;&#x5e55;"/>
</node>
<node CREATED="1448801462454" ID="ID_1664692406" MODIFIED="1448802409104" POSITION="right" STYLE="bubble" TEXT="paintEvent">
<node BACKGROUND_COLOR="#ffffff" CREATED="1448801697605" ID="ID_301671768" MODIFIED="1448802409105" STYLE="bubble" TEXT="&#x91cd;&#x7ed8;&#x754c;&#x9762;&#xff0c;&#x6bcf;&#x4e00;&#x6b21;&#x79fb;&#x52a8;&#x754c;&#x9762;&#x90fd;&#x5c06;&#x91cd;&#x65b0;&#x7ed8;&#x5236;"/>
<node CREATED="1448801835471" ID="ID_994903361" MODIFIED="1448802170435" TEXT="draw background"/>
<node CREATED="1448802170984" ID="ID_253988433" MODIFIED="1448802177157" TEXT="draw number"/>
<node CREATED="1448802440361" ID="ID_992095665" MODIFIED="1448802452597" TEXT="set pen,set font "/>
</node>
<node CREATED="1448801474702" ID="ID_429790862" MODIFIED="1448802463870" POSITION="right" STYLE="bubble" TEXT="keypressEvent">
<node CREATED="1448802496513" ID="ID_248925981" MODIFIED="1448802511670" TEXT="is gameOver"/>
<node CREATED="1448802513648" ID="ID_1229471643" MODIFIED="1448802528500" TEXT="switch key">
<node CREATED="1448802537601" ID="ID_581377540" MODIFIED="1448802554487" TEXT="key_left">
<node CREATED="1448802558529" ID="ID_457548697" MODIFIED="1448802617023" TEXT="move">
<node CREATED="1448802814042" ID="ID_1985223779" MODIFIED="1448802923446" TEXT="&#x5982;&#x679c;&#x4e3a;0,&#x4e0d;&#x5904;&#x7406;"/>
<node CREATED="1448802923978" ID="ID_207639335" MODIFIED="1448802957376" TEXT="&#x5982;&#x679c;&#x4e0d;&#x4e3a;0,&#x5de6;&#x79fb;"/>
</node>
<node CREATED="1448802618393" ID="ID_566645058" MODIFIED="1448802620141" TEXT="add">
<node CREATED="1448804427833" ID="ID_645762321" MODIFIED="1448804468205" TEXT="array[i][j] == array[i][j+1],&#x52a0;">
<node CREATED="1448804531249" ID="ID_1627655430" MODIFIED="1448804578569">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;array[i][k] = array[i][j] * 2;
    </p>
    <p>
      score += array[i][k];
    </p>
    <pre style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">j++</pre>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1448804469281" ID="ID_1248669160" MODIFIED="1448804508061" TEXT="array[i][j] != array[i][j+1],&#x7ee7;&#x7eed;"/>
</node>
</node>
<node CREATED="1448804513608" ID="ID_1280863599" MODIFIED="1448804519196" TEXT="keu_right">
<node CREATED="1448804584745" ID="ID_1009065981" MODIFIED="1448804589726" TEXT="move">
<node CREATED="1448802814042" ID="ID_1031425387" MODIFIED="1448802923446" TEXT="&#x5982;&#x679c;&#x4e3a;0,&#x4e0d;&#x5904;&#x7406;"/>
<node CREATED="1448802923978" ID="ID_264691572" MODIFIED="1448802957376" TEXT="&#x5982;&#x679c;&#x4e0d;&#x4e3a;0,&#x5de6;&#x79fb;"/>
</node>
<node CREATED="1448802618393" ID="ID_210939747" MODIFIED="1448802620141" TEXT="add">
<node CREATED="1448804427833" ID="ID_902264769" MODIFIED="1448804468205" TEXT="array[i][j] == array[i][j+1],&#x52a0;">
<node CREATED="1448804531249" ID="ID_807814230" MODIFIED="1448804708448">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;array[i][k] = array[i][j] * 2;
    </p>
    <p>
      score += array[i][k];
    </p>
    <pre style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">j--;</pre>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1448804469281" ID="ID_985351686" MODIFIED="1448804508061" TEXT="array[i][j] != array[i][j+1],&#x7ee7;&#x7eed;"/>
</node>
</node>
<node CREATED="1448804798265" ID="ID_1467191979" MODIFIED="1448804803504" TEXT="key_Up">
<node CREATED="1448804584745" ID="ID_570868659" MODIFIED="1448804589726" TEXT="move">
<node CREATED="1448802814042" ID="ID_1399406160" MODIFIED="1448802923446" TEXT="&#x5982;&#x679c;&#x4e3a;0,&#x4e0d;&#x5904;&#x7406;"/>
<node CREATED="1448802923978" ID="ID_1566840926" MODIFIED="1448802957376" TEXT="&#x5982;&#x679c;&#x4e0d;&#x4e3a;0,&#x5de6;&#x79fb;"/>
</node>
<node CREATED="1448802618393" ID="ID_1524584147" MODIFIED="1448802620141" TEXT="add">
<node CREATED="1448804427833" ID="ID_687368462" MODIFIED="1448804468205" TEXT="array[i][j] == array[i][j+1],&#x52a0;">
<node CREATED="1448804531249" ID="ID_1322582703" MODIFIED="1448804855337">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;array[k][j] = array[i+1][j] * 2;
    </p>
    <p>
      score += array[i][k];
    </p>
    <pre style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">i++;</pre>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1448804469281" ID="ID_1797358851" MODIFIED="1448804508061" TEXT="array[i][j] != array[i][j+1],&#x7ee7;&#x7eed;"/>
</node>
</node>
<node CREATED="1448804798265" ID="ID_3281831" MODIFIED="1448804884559" TEXT="key_Down">
<node CREATED="1448804584745" ID="ID_106538927" MODIFIED="1448804589726" TEXT="move">
<node CREATED="1448802814042" ID="ID_1136626933" MODIFIED="1448802923446" TEXT="&#x5982;&#x679c;&#x4e3a;0,&#x4e0d;&#x5904;&#x7406;"/>
<node CREATED="1448802923978" ID="ID_1094726332" MODIFIED="1448802957376" TEXT="&#x5982;&#x679c;&#x4e0d;&#x4e3a;0,&#x5de6;&#x79fb;"/>
</node>
<node CREATED="1448802618393" ID="ID_824247255" MODIFIED="1448802620141" TEXT="add">
<node CREATED="1448804427833" ID="ID_935695128" MODIFIED="1448804468205" TEXT="array[i][j] == array[i][j+1],&#x52a0;">
<node CREATED="1448804531249" ID="ID_1943220122" MODIFIED="1448804900729">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;array[k][j] = array[i+1][j] * 2;
    </p>
    <p>
      score += array[i][k];
    </p>
    <pre style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">i--;</pre>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1448804469281" ID="ID_1746683136" MODIFIED="1448804508061" TEXT="array[i][j] != array[i][j+1],&#x7ee7;&#x7eed;"/>
</node>
</node>
<node CREATED="1448804984434" ID="ID_1503266551" MODIFIED="1448804995454" TEXT="give a new rand number"/>
</node>
</node>
<node CREATED="1448801490270" ID="ID_1459105203" MODIFIED="1448805255010" POSITION="right" STYLE="bubble" TEXT="isGameOver">
<node CREATED="1448805257675" ID="ID_456373774" MODIFIED="1448805300637" TEXT="&#x5224;&#x65ad;&#x662f;&#x5426;&#x53ef;&#x4ee5;&#x7ee7;&#x7eed;">
<node CREATED="1448805111021" ID="ID_1418557866" MODIFIED="1448805211945" TEXT="&#x5224;&#x65ad;&#x6bcf;&#x4e00;&#x884c;&#x662f;&#x5426;&#x6709;&#x76f8;&#x540c;&#x7684;&#x6570;&#xff0c;&#x6216;&#x8005;0">
<node CREATED="1448805144372" ID="ID_881280421" MODIFIED="1448805154694" TEXT="if (array[i][j] == array[i][j+1] || array[i][j] == 0)"/>
</node>
<node CREATED="1448805111021" ID="ID_1338618575" MODIFIED="1448805236631" TEXT="&#x5224;&#x65ad;&#x6bcf;&#x4e00;&#x5217;&#x662f;&#x5426;&#x6709;&#x76f8;&#x540c;&#x7684;&#x6570;&#xff0c;&#x6216;&#x8005;0">
<node CREATED="1448805144372" ID="ID_779367693" MODIFIED="1448805154694" TEXT="if (array[i][j] == array[i][j+1] || array[i][j] == 0)"/>
</node>
<node CREATED="1448805314244" ID="ID_1923863108" MODIFIED="1448805324185" TEXT="&#x4e0d;&#x5ae9;&#x7ee7;&#x7eed;"/>
</node>
</node>
</node>
</map>
