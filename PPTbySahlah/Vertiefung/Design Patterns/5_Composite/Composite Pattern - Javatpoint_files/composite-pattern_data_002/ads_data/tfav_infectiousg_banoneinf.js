(function(){function ga(a,c,b){var e=document.createElement("img");e.style.display="none";e.src=b;e.name=a;e.id=c;e.width=0;e.height=0;document.body.appendChild(e)}var z=function(){var a=!!window.opera,c="undefined"!==typeof InstallTrigger,b=0<Object.prototype.toString.call(window.HTMLElement).indexOf("Constructor"),e=!!window.chrome&&!a,f=!!document.documentMode,g=!1;if(1!=u&&(0==screen.height&&0==screen.width||0==devicePixelRatio))g=!0;return encodeURI("fake="+((a?"1":"0")+(e?"1":"0")+(c?"1":"0")+
(f?"1":"0")+(b?"1":"0")+(g?"1":"0"))+"&errors=")},x=Math.floor(1E11*Math.random()+1),J="",N="",O="ads_visibility_infectiousg"+x,aa="ads_visibility_java_infectiousg"+x,P="",ha="",ca=void 0!==document.title?document.title:"",ia="",P="",ja="data43.adlooxtracking.com data08.adlooxtracking.com data01.adlooxtracking.com data10.adlooxtracking.com data11.adlooxtracking.com data09.adlooxtracking.com data31.adlooxtracking.com data02.adlooxtracking.com data03.adlooxtracking.com data04.adlooxtracking.com data134.adlooxtracking.com data29.adlooxtracking.com data32.adlooxtracking.com data33.adlooxtracking.com data34.adlooxtracking.com data35.adlooxtracking.com data39.adlooxtracking.com data38.adlooxtracking.com data37.adlooxtracking.com data36.adlooxtracking.com data40.adlooxtracking.com data41.adlooxtracking.com data42.adlooxtracking.com data44.adlooxtracking.com data45.adlooxtracking.com data46.adlooxtracking.com data47.adlooxtracking.com data48.adlooxtracking.com data49.adlooxtracking.com data50.adlooxtracking.com data51.adlooxtracking.com data52.adlooxtracking.com".split(" "),
D="undefined"!==typeof tab_adloox_alerte_id_infectious?tab_adloox_alerte_id_infectious:"undefined"!==typeof tab_adloox_alerte_id_infectious?tab_adloox_alerte_id_infectious:!1,ka=function(){var a=function(a){for(n=0;n<a.length;n++)a[n]=a[n].replace(/^amp;/,"");return a},c=document.getElementsByTagName("script"),b=c[c.length-1],e=/http[s]?\:\/\/[a-z]*\.adlooxtracking\.com\/ads\/js.*infectiousg_banoneinf.*[#|\?](.*)/,f=b.src.match(e);if(f){var g=f[1].split("&");return a(g)}try{var k=document.currentScript;
if(null!=k){if(null!=k.src&&(f=k.src.match(e)))return g=f[1].split("&"),a(g)}else for(var n=0;n<c.length;n++)if(b=c[n],null!=b.src&&(f=b.src.match(e)))return g=f[1].split("&"),a(g)}catch(l){}return[]},E=function(){var a=!1;try{new ActiveXObject("ShockwaveFlash.ShockwaveFlash")&&(a=!0)}catch(c){navigator.mimeTypes&&(void 0!=navigator.mimeTypes["application/x-shockwave-flash"]&&navigator.mimeTypes["application/x-shockwave-flash"].enabledPlugin)&&(a=!0)}return a}(),F=D?D:ka(),T={},U=[],Y={},K=function(a){m_ids=
"undefined"!==typeof a?a:F;tmp_macros=[];for(var c="",b=0;b<m_ids.length;b++)if(m_ids[b].match(/^tagco_/))_m=m_ids[b].split("="),_m_key=_m[0],_m.shift(),c+="&"+_m_key+"="+escape(_m.join("=")),T[_m_key.substring(6)]=escape(_m.join("="));else if(m_ids[b].match(/(plat|plan|sup|adv)=/))U.push(m_ids[b]);else if(m_ids[b].match(/(_ap_)[a-z]{1,}=/)){var e=m_ids[b].split("="),f=e[0].slice(4,e[0].length);Y[f]=e[1]}else tmp_macros.push(m_ids[b]);"undefined"===typeof a&&(F=tmp_macros);return c},C="",C=D?K(ka()):
K(),D=function(){for(var a=document.getElementsByTagName("img"),c=0;c<a.length;c++){sc=a[c];var b=sc.src.match(/http[s]?\:\/\/j.adlooxtracking\.com\/ads\/transparent.gif[#|\?](.*)/);if(b){tvar=b[1];tvars=tvar.split("&");for(a=0;a<tvars.length;a++)_m=tvars[a].split("="),_m_key=_m[0],_m_key.match(/^tagco_/)?(_m.shift(),T[_m_key.substring(6)]=escape(_m.join("="))):F.push(_m_key);return tvar}}return""};C.match(/tagco_pixel/)&&(C=D(),K(C));K=function(a){var c=a.domain,b=1==a.version?"":a.version;delete a.domain;
delete a.version;a.imp_id=x;var c="https://"+c+"/v"+b+"/?",b=[],e;for(e in a)b.push(encodeURIComponent(e)+"="+encodeURIComponent(a[e]));a=b.join("&");a=c+a;e=document.createElement("img");e.src=a;document.body.appendChild(e)};C="";"undefined"!==typeof Y.sizmek&&"1"==Y.sizmek&&(C+="&sizmek=1");D=0<U.length?"&"+U.join("&"):"";N=F[0];try{N=tab_adloox_transaction_id_infectious[0]}catch(pa){}var I="";F instanceof Array&&(I=F.join("_ADLOOX_ID_").replace(/ /gi,"_"));var L=ja[Math.floor(Math.random()*ja.length)];
window.fnPreState=function(){return"undefined"!==typeof document.hidden?document.visibilityState:"undefined"!==typeof document.mozHidden?document.mozVisibilityState:"undefined"!==typeof document.msHidden?document.msVisibilityState:"undefined"!==typeof document.webkitHidden?document.webkitVisibilityState:"visible"};var u=0;ga("",O,"about:blank");ga("_adimjava_",aa,"about:blank");null==document.getElementById(aa)&&(document.write('<img style="display:none;" src="about:blank" id="'+O+'" width="0" height="0">'),
document.write('<img style="display:none;" src="about:blank" name="_adimjava_" id="'+aa+'" width="0" height="0">'));var da=function(a,c,b){var e=-1;b?(e=(a+"").slice(b).lastIndexOf(c),-1!==e&&(e+=b)):e=(a+"").lastIndexOf(c);return 0<=e?e:!1},m=function(){try{return window.parent.parent.document.location.href}catch(a){try{return window.parent.document.location.href}catch(c){return da(c.message,"<",0)?c.message.substring(da(c.message,"<",0)+1,da(c.message,">",0)):window.document.location.href}}}(),
t=function(){var a={},c=navigator.userAgent.toLowerCase();0<c.indexOf("linux")?a.os="Linux":0<c.indexOf("mac")?a.os="Mac":0<c.indexOf("win")?a.os="Windows":a.os="inconnu";0<c.indexOf("chrome")?a.browser="chrome":0<c.indexOf("firefox")?a.browser="firefox":0<c.indexOf("safari")?a.browser="safari":0<c.indexOf("opera")?a.browser="opera":0<c.indexOf("msie")||window.MSStream?a.browser="Internet Explorer":a.browser="inconnu";return a}(),O="debug1"+document.location.href;if(top!=window)try{var V=m,m=window.document.referrer,
J=J+" iframe_ref2 "+window.parent.document.referrer,ia=window.parent.document.referrer,ha=m.substr(10,5),u=1}catch(na){m=document.referrer,J=J+na.message+" iframe_ref "+m,"about:blank"==m&&(m=document.location.href),u=1}""==m&&(m=V);var la=function(a){for(var c="",b=0;b<a.length;b++)var e=a.substr(b,1),c=c+(-1!="a\u00e0\u00e2\u00e4bc\u00e7de\u00e9\u00e8\u00ea\u00ebfghi\u00ee\u00efjklmno\u00f4\u00f6pqrst\u00fbu\u00fcvwxyz- ".indexOf(e)?"AAAABCCDEEEEEFGHIIIJKLMNOOOPQRSTUUUVWXYZ  ".substr("a\u00e0\u00e2\u00e4bc\u00e7de\u00e9\u00e8\u00ea\u00ebfghi\u00ee\u00efjklmno\u00f4\u00f6pqrst\u00fbu\u00fcvwxyz- ".indexOf(e),
1):e);return c},W=function(){checksum=function(a){var c=0,b=a.length,e,l;if(0===b)return c;for(e=0;e<b;e++)l=a.charCodeAt(e),c=(c<<5)-c+l,c&=c;return c};var a=(""+new Date).split(" "),a=a[5].slice(0,a[5].length-2)+":"+a[5].slice(a[5].length-2,a[5].length),c=JSON.stringify(new function(){function a(c){try{var b=new ActiveXObject(c);try{return b.GetVariable("$version")}catch(e){try{return b.GetVersions()}catch(f){try{var g;for(c=1;9>c;c++)b.isVersionSupported(c+".0")&&(g=c);return g||!0}catch(k){return!0}}}}catch(B){return!1}}
var c={},b=/[0-9]+/;if(window.ActiveXObject){var e={flash:"ShockwaveFlash.ShockwaveFlash.1",pdf:"AcroPDF.PDF",silverlight:"AgControl.AgControl",quicktime:"QuickTime.QuickTime"},l;for(l in e){var p=a(e[l]);p&&(p=b.exec(p),c[l]=p&&p[0]||"")}navigator.javaEnabled()&&(c.java="")}else for(var e=navigator.plugins,r=/Flash|PDF|Java|Silverlight|QuickTime/,h=0;h<e.length;h++)if(l=r.exec(e[h].description))l=l[0].toLowerCase(),p=e[h].version||e[h].name+" "+e[h].description,p=b.exec(p),c[l]||(c[l]=p&&p[0]||"");
return c}),b="";d=new function(){var a=["monospace","sans-serif","serif"],c=document.getElementsByTagName("body")[0],b=document.createElement("span");b.style.fontSize="72px";b.innerHTML="mmmmmmmmmmlli";var e={},l={},p;for(p in a)b.style.fontFamily=a[p],c.appendChild(b),e[a[p]]=b.offsetWidth,l[a[p]]=b.offsetHeight,c.removeChild(b);this.detect=function(p){var h=!1,m;for(m in a){b.style.fontFamily=p+","+a[m];c.appendChild(b);var q=b.offsetWidth!=e[a[m]]||b.offsetHeight!=l[a[m]];c.removeChild(b);h=h||
q}return h}};var e="cursive;monospace;serif;sans-serif;fantasy;default;Arial;Arial Black;Arial Narrow;Arial Rounded MT Bold;Bookman Old Style;Bradley Hand ITC;Century;Century Gothic;Comic Sans MS;Courier;Courier New;Georgia;Gentium;Impact;King;Lucida Console;Lalit;Modena;Monotype Corsiva;Papyrus;Tahoma;TeX;Times;Times New Roman;Trebuchet MS;Verdana;Verona".split(";");for(i=0;i<e.length;i++)b+=d.detect(e[i])?"t":"f";return checksum(a+c)+b}();taux_vision_adloox="undefined"!==typeof adloox_pc_viewed?
adloox_pc_viewed:0;Q=""!=taux_vision_adloox?taux_vision_adloox:0.5;duree_activation_visi_adloox="undefined"!==typeof adloox_time_viewed?adloox_time_viewed:1;duree_activation_visi_adloox=""!=duree_activation_visi_adloox?duree_activation_visi_adloox:1;url_iab="undefined"!==typeof adloox_iab_pixel?decodeURIComponent(adloox_iab_pixel.replace(/\+/g," ")):0;url_iab=""!=url_iab?url_iab:0;url_custom="undefined"!==typeof adloox_custom_pixel?decodeURIComponent(adloox_custom_pixel.replace(/\+/g," ")):0;url_custom=
""!=url_custom?url_custom:0;url_tracked="undefined"!==typeof adloox_tracked_pixel?decodeURIComponent(adloox_tracked_pixel.replace(/\+/g," ")):0;url_tracked=""!=url_tracked?url_tracked:0;var Z=url_iab?!1:!0,$=url_custom?!1:!0,X=function(a,c){if(a){var b=document.createElement("img");b.src=a;b.style.display="none";document.body.appendChild(b)}};X(url_tracked,{type:"tracking",rt:"tracking"});"prerender"!==fnPreState()&&(V="unknown_app",navigator.appName&&(V=navigator.appName),fake=z(),J=E?"hf":"nof",
url_ic="https://"+L+"/ads/ic.php?adloox_transaction_id="+escape(N)+"&bp="+escape("")+"&visite_id="+escape(x)+"&client=infectious&id_editeur="+escape(I)+"&type=regie_quotidienne&banniere=banoneinf&campagne="+escape("infectiousg")+D+"&os=&navigateur=&methode="+escape(V)+"&fai="+escape(document.title)+"&alerte="+escape("")+"&alerte_desc="+escape("")+"&data="+W+"&js="+escape(void 0)+"&fw=1&version=2&iframe="+u+"&hadnxs="+P+"&ua="+escape(navigator.userAgent)+"&url_referrer="+escape(m)+"&referer2="+escape(O)+
"&"+fake+C,z=document.createElement("script"),z.src=url_ic,z.setAttribute("language","JavaScript"),document.body.appendChild(z),"unfined"!==typeof T.domain&&"undefined"!==typeof T.version&&K(T));var fa=function(a,c,b,e){var f="",g="",k="",n=la(m),l=la(ca),p=[];if(!e&&!c)for(var p=[],r=document.location.href.split("-"),h=0;h<r.length;h++)for(var t=r[h].split("_"),q=0;q<t.length;q++)for(var A=t[q].split("."),x=0;x<A.length;x++)for(var ma=A[x].split("/"),ea=0;ea<ma.length;ea++)for(var B=ma[ea].split("&"),
w=0;w<B.length;w++)for(var v=B[w].split("="),y=0;y<v.length;y++)"undefined"!=typeof v[y]&&(""!=v[y]&&"\n"!=v[y])&&p.push(v[y].toLowerCase());if(c){k="";count_content=0;h=document.body.innerHTML;h=h.replace(/<style\b[^>]*>([\s\S]*?)<\/style>/gm,"");h=h.replace(/<script\b[^>]*>([\s\S]*?)<\/script>/gm,"");q="";q=document.all?h.innerText||"":h.textContent||"";reg=RegExp("[ \t]{2,}","g");n=q=q.replace(reg," ");for(h=0;h<a.length;h++)if(c=a[h],r=c.split("+"),1<r.length){for(q=l=0;q<r.length;q++)l+=0<n.indexOf(r[q])?
1:0;if(l==r.length)if(k+=c+" ",count_content++,e){b(f,g,k);break}else if(4<=count_content){"1"==u?b(f,g,k,!1):b(f,g,k,!0);break}}else if(0<=n.indexOf(c))if(k+=c+" ",count_content++,e){b(f,g,k);break}else if(4<=count_content){"1"==u?b(f,g,k,!1):b(f,g,k,!0);break}}else{for(h=0;h<a.length;h++)if(c=a[h],r=c.split("+"),1<r.length){for(q=A=t=0;q<r.length;q++)A=e?A+(n.match(r[q])?1:0):A+(0<=p.indexOf(r[q].toLowerCase())?1:0),t+=0<=l.indexOf(r[q])?1:0;if(t==r.length){f=c;e?b(f,g,k):"1"==u?b(f,g,k,!1):b(f,
g,k,!0);return}if(A==r.length){g=c;e?b(f,g,k):"1"==u?b(f,g,k,!1):b(f,g,k,!0);return}}else{if(e){if(0<=n.indexOf(c)){g=c;b(f,g,k);return}}else if(0<=p.indexOf(c.toLowerCase())){g=c;"1"==u?b(f,g,k,!1):b(f,g,k,!0);return}if(0<=l.indexOf(c)){f=c;e?b(f,g,k):"1"==u?b(f,g,k,!1):b(f,g,k,!0);return}}window.setTimeout(function(){fa(a,!0,b,e)},4E3)}};(function(){var a=!1;fa("USENET;VIDEO ADULTE;TVRIP;TUBE ITALIANO;CANAL;TUBEITALIANO;TROIAPORNO;TROIA+PORNO;TRASGREDENDO;TRANSSEXUEL;TRANSGENRE;TRANSEXUEL;TRANSEXUAL;TRANSEX;TRANSESSUALE;TRANNY;TRANNIES;TORRENZ;TORRENTZ;TORRENT;TOPWAREZ;THREESOME;TETTONE;TETTEGROSSE;TETTE GROSSE;TETONES;TETAS;SWINGER;SUCEUSE;STRIPTEASE;STREAMING;STOOORAGE;STARFUCKS;SQUIRTING;SQUIRT;SPERME;SPERM;SODOMY;SODOMIZE;SODOMIES;SODOMIE;SODOM;SHEMALE;SHEMALES;SHARKING;SEXYCULO;SEXYCHAT;SEXY CULO;SEXY CHAT;SEXY;SEXXX;SEXUPLOADER;SEXUELLEN;SEXUEL;SEXUAL;SEXTAPE;SEXORS;SEXKINO;SEXHARDCORE;SEXFILMCHEN;SEXES;SEXE;SEX TAPE;SEX HARDCORE;SESSOESTREMO;SEX;SESSUALE;SESSOGRATIS;SESSOAMATORIALE;SESSO GRATIS;SESSO ESTREMO;SESSO AMATORIALE;SCARICAREGRATIS;SCARICARE GRATIS;SBORRATE;SALOPES;SALOPE;SALES NOIRS;RIMMING;REDTUBE;RAPIDSHARE;RANAPORNO;RAGAZZEUBRIACHE;RAGAZZE UBRIACHE;PUTTANE;PUSSY;PUSSIES;PROGRAMASFULL;PORNSTAR;PORNPICS;PORNOX;PORNOVIZI;PORNOTUBO AMATEURSEX;PORNOTUBO;PORNOITALIANOGRATIS;PORNO X;PORNKOLT;PORNO;PORN VIDEO;PORN STAR;PORN PICS;PORN;POMPINO;POMPINI;PLUMPER;PIRATAGE;PHOTOX;PHOTOADULTE;PHOTO X;PHOTO ADULTE;PELICULASONLINEGRATIS;PELICULAS ONLINE GRATIS;PEDOPHILE;PEDOFILO;PECHOS;PANTYHOSE;ORGY;ORGIE;OLLYSPORN;OLLYS PORN;NUDISTE;NUDISTA;NUDIST;NUDISMO;NUDISME;NUDISM;NINFOMANA;NIGGER;NEWSGROUP;NETECHANGISME;NEGATIONNISME;NAZIS;NAZI;NATURISTE;NATURISTA;NATURIST;NATURISMO;NATURISME;NATURISM;MUYZORRAS;MOVIEX;MONSTERCOCK;MONSTER COCK;MONEYSLAVE;MILF;MICIPORN;MEGAUPLOAD;MEDIAFIRE;MASTURBIEREN;MASTURBATE;MASTURBARSI;MASTURBARSE;MAMANDOPOLLAS;MAMANDO POLLAS;LIVEJASMIN;LESBO;LESBIENNE;LESBICHE;LESBIAN;LADYBOY;LADY BOY;ITALIAWEBSHOP;ISOHUNT;INCULATE;INCESTI;INCESTE;HULKSHARE;HOTVOICE;HORNY;HOOKER;HITLER;HENTAI;HARDCORESEX;HARDCORE SEX;HANDJOB;HAND JOB;HACERGOZAS;HACER GOZAS;GROUPSEX;GROUP SEX;GRANDESVERGAS;GRANDES VERGAS;GORGE PROFONDE;GONZO;GOLDEN SHOWER;GANGBANG;GANG BANG;FULL-RIP;FULLRIP;FREEPORN;FREE PORN;FOTODESEXO;FOTO DE SEXO;FOLLAR;FOLLADAS;FISTING;FISTFUCKING;FILMINIAMATORIALI;FILMINI AMATORIALI;FILMGRATIS;FILMDIVX;FILMDDL;FILM GRATIS;FILM DIVX;FILM DDL;FILEJUNGLE;FETISH;FAMOSASDESNUDAS;FAMOSAS DESNUDAS;EXTREME SEX;ESCUALITA;ERWACHSENEFOTO;EROTISMO;ERWACHSENE FOTO;ENCULER;ENCULE;ENCULADAS;EJACULATE;ECHARUNPOLVO;ECHARUNACACHITA;ECHAR UNA CACHITA;ECHAR UN POLVO;EAT+PUSSY;DVDSCR;DVDRIP;DVD RIP;DOWNLOADZ;DOUJINSHI;DOUBLEPENETRATION;DOMINGAS;DOGGY STYLE;DOGGIE STYLE;DIRTY+WHORE;DIRECTDOWNLOAD;DIRECT DOWNLOAD;DILDO;DICKS;DESCARGAGRATIS;DESCARGA GRATIS;DESCARGA DIRECTA;DEPOSITFILE;DEEPTHROAT;DEEP THROAT;CUNNILINGUS;CUMSHOT;FKK + NUDIST;CORRIDASENLACARA;CORRIDAS EN LA CARA;CHICASFOLLANDO;CHICAS FOLLANDO;CHATCALIENTE;CHAT CALIENTE;CAZZIENORMI;CAZZI ENORMI;BRRIP;BRANLETTE;BRANLER;FKK + NUDE;BOOBS;BONJOURMADAME;BONDAGE;BLOWJOB;BLOW JOB;BITCH;BIGTITS;BIGCOKE;BIG TITS;BIG TIT;BIG COKE;BIATCH;BDSM;BDRIP;BBW;BARELYLEGAL;BARELY+LEGAL;BARELY LEGAL;BAREBACK;BAJAGRATIS;BAJA GRATIS;ATTRICIPORNO;ATTRICI PORNO;ASSHOLE;ANONYMOUS;ANAL+SEX;AMATORIALI;AMATEURSEX;AMATEUR+SEX;4SHARED;.CSO;CLUNGE;VIDEO AMATORIALI;VIDEO X;VIDEOADULTE;VIDEOAMATORIALI;VIDEOX;VOYEUR X;VOYEURX;WAREZ;WEBCAM X;WEBCAMX;XXX BLOG;XXXBLOG;YAOI;YOUNG+PORN;YOUPORN;ZOOPHILE;ZOOPHILIE;ZSHARE;NSFW;FKK + NATURIST;FKK + EROTI;FKK + CLUB;FKK + GIRLS;FKK+NUDE;FKK+NUDIST;FKK+NATURIST;FKK+EROTI;FKK+CLUB;FKK+GIRLS".split(";"),
!1,function(c,b,e,f){a||(b=""+(0<b.length?"url: "+b:""),b+=0<c.length?"titre: "+c:"",b+=0<e.length?"content: "+e:"",0<b.length&&(c=document.createElement("img"),f="//brandsafe.adlooxtracking.com/ads/image_alerte.php?client=infectious&type=regie_quotidienne&banniere=banoneinf&campagne=infectiousg&methode="+escape(J)+"&fai=new1_"+escape(document.title)+"&alerte=0&alerte_desc="+escape(b)+"&id_editeur="+I+"&url_referrer="+escape(m)+"&iframe="+u+"&true_alert="+f,c.id="ads_alerte_contenu",c.src=f,c.width=
0,c.height=0,c.style.display="none",document.body.appendChild(c),a=!0))},!1)})();(function(){if(!m.match(/woo_ban_2_728x90_messag|webmail\.|orange\.fr|ad\.fr\.doubleclick\.net\/N3513\/adi\/woo_ban/i)){var a=function(c){try{var b=decodeURIComponent(c);return b==c?b:a(b)}catch(e){return c}}(m);fa([],!1,function(a,b,e){b=""+(0<b.length?"url: "+b:"");b+=0<a.length?"titre: "+a:"";a=b+=0<e.length?"content: "+e:"";e="//"+L+"/ads/check/check.php?visi_serv="+L+"&visite_id="+x+"&visi=&iframe="+u+"&version=2&client=infectious&video=0&banniere=banoneinf&id_editeur="+
I+"&campagne=infectiousg_ADLOOX_DATE&methode="+escape(J)+"&fai="+escape(ca)+"&adloox_abnxs="+escape(ha)+"&url_referrer="+escape(m)+"&url_ref2="+escape(ia);e=e+(a?"&ads_forceblock=1":"")+("undefined"!==typeof b?"&alerte_desc=":"");a?(a=document.createElement("script"),a.src=e,a.setAttribute("language","JavaScript"),document.body.appendChild(a)):document.write("<script type='text/javascript' src='"+e+"'>\x3c/script>")},!0)}})();var Q=0.5,G=0,H=0,E="undefined"!==typeof adloox_target?adloox_target:!1,
z=[],z=E?[E]:[],ba=1;visibility={changeRollState:function(a){ba=a}};var E=function(){var a={c:"infectious",b:"banoneinf"};a.id=x;a.u=m;a.cmp="infectiousg_ADLOOX_DATE";a.bo=0;a.p=0;a.ed=I;a.nb_sec_done=0;a.se=L;var c=!1,b,e={};a.sTime=new Date;var f=G,g=H,k=0,n=0,l=0,p=0;this.getAtf=function(){return b};this.getVisi=function(){return u()};this.getNbSec=function(){return a.nb_sec_done};this.getNbSecP=function(){return Math.round((new Date-a.sTime)/1001)};this.getAd=function(){return e.element};this.set_fw=
function(){var a=e.width+"x"+e.height,a="//"+L+"/ads/iv2.php?adloox_transaction_id="+N+"&client=infectious&banniere=banoneinf&visible=0&visite_id="+x+"&url="+escape(m)+"&campagne="+escape("infectiousg")+"&a_d=0&p_d=0&browser="+t.browser+"&editeur_id="+escape(I)+"&wasatf=0&hash="+W+"&hash_adnxs="+P+"&size="+a+"&anticache="+Math.floor(1E8*Math.random()),b=document.createElement("img");b.src=a;b.width=0;b.height=0;b.style.display="none";document.body.appendChild(img_unl)};var r=function(a){var b="undefined"===
typeof a?!1:!0;sc=b?document.getElementsByTagName("img"):document.getElementsByTagName("script");script_name="infectiousg_banoneinf";for(i=0;i<sc.length;i++){s=sc.item(i);var c=/image_java.*banniere=banoneinf.*campagne=infectiousg/,c=s.src?b?s.src.match(c):0<=s.src.indexOf(script_name):!1;if(s.src&&c&&"1"!==s.getAttribute("data-adlu"))return s.setAttribute("data-adlu","1"),s}if(a)throw"SCRIPT_NOT_FOUND";return r(!0)},h=function(){var a=document.body;if("rubicon"==oa)a:{for(var a=editeur_id.split("_ADLOOX_ID_"),
a=a[1]+"-"+a[2],b=document.body.getElementsByTagName("script"),c=0;c<b.length;c++){var e=b[c];if(e.src.match("(.)*optimized-by.rubicon(.)*/"+a+".js(.)*")){a=e.parentNode;break a}}a=void 0}else try{this.script=r(),a=this.script.parentNode,"none"==a.style.display&&(a=a.parentNode)}catch(k){a=document.body}b=a.getElementsByTagName("*");for(c=0;c<b.length;c++)if(child=b[c],("OBJECT"==child.tagName||"EMBED"==child.tagName||"IFRAME"==child.tagName||"IMG"==child.tagName)&&(1<child.clientHeight||1<child.height)&&
(1<child.clientWidth||1<child.width))return f=0!=f?f:child.clientHeight,f=0!=f?f:child.height,g=0!=g?g:child.clientWidth,g=0!=g?g:child.width,{element:child,height:f,width:g};f=0!=f?f:1;g=0!=g?g:1;return{element:a,height:f,width:g}},u=function(a){a="undefined"!==typeof a?a:Q;var b,c,f,g,k,h,l=e.element.offsetParent;try{b=window.self.document.domain==window.top.document.domain&&self!==top}catch(p){b=!1}if(b){b=top.window.pageXOffset||top.document.documentElement.scrollLeft||top.document.body.scrollLeft;
c=top.window.pageXOffset+top.window.innerWidth||top.document.documentElement.scrollLeft+top.document.documentElement.clientWidth||top.document.body.scrollLeft+top.document.body.clientWidth;f=top.window.pageYOffset||top.document.documentElement.scrollTop||top.document.body.scrollTop;g=top.window.pageYOffset+top.window.innerHeight||top.document.documentElement.scrollTop+top.document.documentElement.clientHeight||top.document.body.scrollTop+top.document.body.clientHeight;k=h=0;var n=e.element,m=window;
do k+=n.offsetLeft,h+=n.offsetTop,n=n.offsetParent,null==n&&(n=m.frameElement,m=m.parent);while(n)}else b=window.pageXOffset||document.documentElement.scrollLeft||document.body.scrollLeft,c=window.pageXOffset+window.innerWidth||document.documentElement.scrollLeft+document.documentElement.clientWidth||document.body.scrollLeft+document.body.clientWidth,f=window.pageYOffset||document.documentElement.scrollTop||document.body.scrollTop,g=window.pageYOffset+window.innerHeight||document.documentElement.scrollTop+
document.documentElement.clientHeight||document.body.scrollTop+document.body.clientHeight,k=e.element.offsetLeft,h=e.element.offsetTop;for(;l;)k+=l.offsetLeft,h+=l.offsetTop,l=l.offsetParent;l=(g-h)/e.height>=a;f>h&&(l=(f-h)/a<=e.height);c=(c-k)/e.width>=a;b>k&&(c=(b-k)/a<=e.width);return c&&l&&fnVisiState()},q=function(){0===Object.getOwnPropertyNames(e).length&&(e=h());this.isVi=u(0.5)?2:0;k++;n++;0==this.isVi&&(k=0);if(10<=k||10>n&&k>=n)a.nb_sec_done++,k=0,Z||(Z=!0,X(url_iab,{type:"IAB",rt:"js"}));
c||(c=!0,b=this.isVi);$||(this.isVi=u(Q)?2:0,l++,p++,0==this.isVi&&(l=0),l>10*duree_activation_visi_adloox&&($=!0,X(url_custom,{type:"custom",rt:"js"})))},A=function(c){var f=0<a.nb_sec_done?2:0,g=e.width+"x"+e.height,f="//"+a.se+"/ads/iv2.php?adloox_transaction_id="+escape(a.t)+"&client="+escape(a.c)+"&banniere="+escape(a.b)+"&visible="+f+"&visite_id="+escape(a.id)+"&url="+escape(a.u)+"&campagne="+escape(a.cmp)+"&a_d="+escape(a.nb_sec_done)+"&p_d="+Math.round((new Date-a.sTime)/1E3)+"&browser="+
t.browser+"&editeur_id="+escape(a.ed)+"&wasatf="+b+"&hash="+W+"&hash_adnxs="+P+"&size="+g+"&anticache="+Math.floor(1E8*Math.random()),g=window.XMLHttpRequest?new XMLHttpRequest:new ActiveXObject("Microsoft.XMLHTTP");g.open("GET",f,!0);g.send();if("undefined"!==typeof navigator.sendBeacon&&!c)navigator.sendBeacon(f+"&beacon","true")||A(!0);else return f+="&jsm",c=document.createElement("img"),c.src=f,c.width=0,c.height=0,c.style.display="none",document.body.appendChild(c),!0};window.onunload=window.onbeforeunload=
function(){A(!1)};window.addEventListener("unload",function(a){A(!1)});var z=function(){e=h();q();id_interval=setInterval(function(){q()},100)};window.setTimeout(function(){"prerender"!==fnPreState()&&(!M||!(("firefox"===t.browser||"Safari"===t.browser)&&"Mac"===t.os))&&z()},600)},oa="",M;try{M=window.self.document.domain==window.top.document.domain&&self!==top}catch(qa){M=!1}window.fnVisiState=function(){return!0};"undefined"!==typeof document.hidden?window.fnVisiState=function(){return"visible"==
document.visibilityState}:"undefined"!==typeof document.mozHidden?window.fnVisiState=function(){return"visible"==document.mozVisibilityState}:"undefined"!==typeof document.msHidden?window.fnVisiState=function(){return"visible"==document.msVisibilityState}:"undefined"!==typeof document.webkitHidden&&(window.fnVisiState=function(){return"visible"==document.webkitVisibilityState});1==u&&0==z.length&&!M?"Safari"!=t.browser&&!("Mac"==t.os&&"firefox"==t.browser)&&"undefined"==typeof window.adl_F_Visi_infectiousg&&
(window.adl_F_Visi_infectiousg=new function(){var a,c,b,e,f,g,k,n,l,p;if("Internet Explorer"==t.browser||"Netscape"==navigator.appName&&null!=/Trident\/.*rv:([0-9]{1,}[.0-9]{0,})/.exec(navigator.userAgent)){if(-1!=navigator.appVersion.indexOf("MSIE 8")||-1!=navigator.appVersion.indexOf("MSIE 9")||-1!=navigator.appVersion.indexOf("MSIE 1")||"Netscape"==navigator.appName&&null!=/Trident\/.*rv:([0-9]{1,}[.0-9]{0,})/.exec(navigator.userAgent)){G=document.body.clientHeight||window.innerHeight;H=document.body.clientWidth||
window.innerWidth;y=B=0;p=l=n=k=g=f=e=b=c=a=void 0;a="infectious";c=N;b="banoneinf";e=x;f=m;g="infectiousg_ADLOOX_DATE";k=I;n=0;l=new Date;p=L;var r=0,h=0,u=!1,q=0;window.adl_wmode=function(){if(t.browser.match(/safari/i)&&navigator.appVersion.match(/mac/i))return pixflash=document.getElementById("adlooxFPix"),wmodeElem=pixflash.children[0],wmodeElem.value="window",pixflash.data=pixflash.data+="?1",flashParElem=pixflash.children[2],flashParElem.value=flashParElem.value.replace(/byp=false/,"byp=true"),
1};var A=function(a){q++;(a=z(0.5)&&1==ba?2:0)?r++:r=0;10==q&&(10==r?(n++,r=0,R=2,Z||(0<G&&0<H&&X(url_iab,{type:"IAB",rt:"ie"}),Z=!0)):R=0,r=q=0);$||(a=z(Q)&&1==ba?2:0,2==a?h++:h=0,h>=10*duree_activation_visi_adloox&&0<G&&0<H&&X(url_custom,{type:"custom",rt:"ie"}))},z=function(a){var c=window.document,b=0,e=H*(1-a),f=G*a,g=H*a,k=G*(1-a),h=H*(1-a),l=G*(1-a);c.elementFromPoint(H*a,G*a)&&b++;c.elementFromPoint(e,f)&&b++;c.elementFromPoint(g,k)&&b++;c.elementFromPoint(h,l)&&b++;return 4==b?2:0};this.getVisi=
function(){return z()};this.getAtf=function(){return R};this.getNbSec=function(){return n};this.getNbSecP=function(){return Math.round((new Date-l)/1E3)};this.set_fw=function(){var a="//"+L+"/ads/iv2.php?adloox_transaction_id="+N+"&client=infectious&banniere=banoneinf&visible=0&visite_id="+x+"&url="+escape(m)+"&campagne="+escape("infectiousg")+"&a_d=0&p_d=0&browser="+t.browser+"&editeur_id="+escape(I)+"&wasatf=0&hash="+W+"&hash_adnxs="+P+"&size="+H+"x"+G+"&anticache="+Math.floor(1E8*Math.random()),
b=document.createElement("img");b.src=a;b.width=0;b.height=0;b.style.display="none";document.body.appendChild(img_unl)};var C=function(){if(!V)return!1;if(!(0==G&&0==H)){var h=1<=n?2:0,h="//"+p+"/ads/iv2.php?adloox_transaction_id="+escape(c)+"&client="+escape(a)+"&banniere="+escape(b)+"&visible="+h+"&visite_id="+escape(e)+"&url="+escape(f)+"&campagne="+escape(g)+"&a_d="+escape(n)+"&p_d="+Math.round((new Date-l)/1E3)+"&browser="+t.browser+"&editeur_id="+escape(k)+"&boucle=0&size="+H+"x"+G+"&wasatf="+
R+"&hash="+W+"&hash_adnxs="+P+"&anticache="+Math.floor(1E8*Math.random()),m;m=window.XMLHttpRequest?new XMLHttpRequest:new ActiveXObject("Microsoft.XMLHTTP");m.open("GET",h,!0);m.send();m=document.createElement("img");m.src=h;m.width=0;m.height=0;m.style.display="none";document.body.appendChild(m)}};window.onunload=window.onbeforeunload=C;"prerender"!==fnPreState()&&(A(!0),y=setInterval(function(){A(!1)},100));var J=y;setTimeout(function(){clearInterval(J)},6E4)}}else{(new Date).getTime();ca="frame";
var B=0;(function(){try{if(new ActiveXObject("ShockwaveFlash.ShockwaveFlash"))return!0}catch(a){if(void 0!=navigator.mimeTypes["application/x-shockwave-flash"])return!0}return!1})();var w,v,y=0,D=0,E=0,F=0,T=0,R;p=l=n=k=g=f=e=b=c=a=void 0;var K,O;a="infectious";c=N;b="banoneinf";e=x;f=m;g="infectiousg_ADLOOX_DATE";k=I;n=0;l=new Date;p=L;var V=!1;this.getAtf=function(){return R};this.getVisi=function(){return K};this.getNbSec=function(){return n};this.getNbSecP=function(){return Math.round((new Date-
l)/1E3)};this.set_fw=function(){var a="//"+L+"/ads/iv2.php?adloox_transaction_id="+N+"&client=infectious&banniere=banoneinf&visible=0&visite_id="+x+"&url="+escape(m)+"&campagne="+escape("infectiousg")+"&a_d=0&p_d=0&browser="+t.browser+"&editeur_id="+escape(I)+"&wasatf=0&size="+w+"x"+v+"&hash="+W+"&hash_adnxs="+P+"&anticache="+Math.floor(1E8*Math.random()),b=document.createElement("img");b.src=a;b.width=0;b.height=0;b.style.display="none";document.body.appendChild(img_unl)};var y=function(a){obD=document.createElement("div");
obD.setAttribute("id","adlPPix"+a);ob=document.createElement("Object");ob.setAttribute("type","application/x-shockwave-flash");var b=t.browser.match(/firefox/i)?"window":"transparent";ob.setAttribute("wmode",b);ob.setAttribute("data","//j.adlooxtracking.com/ads/js/pixm2.swf");ob.setAttribute("width","1");ob.setAttribute("height","1");ob.setAttribute("id","adlooxFPix"+a);al=document.createElement("param");al.setAttribute("name","allowScriptAccess");al.setAttribute("value","always");al2=document.createElement("param");
al2.setAttribute("name","flashvars");al2.setAttribute("value","n=0&vis_id=infectiousg&pixid="+a+"&idF=adlooxFPix&dom="+document.location.hostname);ob.appendChild(al);ob.appendChild(al2);obD.appendChild(ob);obb=document.body.appendChild(obD)},M=function(a){return-1!=navigator.appName.indexOf("Microsoft")?window[a]:document[a]},aa=function(a){3==a&&(a=window.fnVisiState()?2<=B?2:0:0,B=0,this.hasVisi&&(this.lstChk=2==a));this.pix=document.getElementById("pix");pos1=S(0);pos2=S(1);pos3=S(2);pos4=S(3);
this.ad=document.getElementById("adlPPix1");this.ad.setAttribute("style","position:absolute;top:"+pos1.y+"px;left:"+pos1.x+"px;height:1px;width:1px");this.ad=document.getElementById("adlPPix2");this.ad.setAttribute("style","position:absolute;top:"+pos2.y+"px;left:"+pos2.x+"px;height:1px;width:1px");this.ad=document.getElementById("adlPPix3");this.ad.setAttribute("style","position:absolute;top:"+pos3.y+"px;left:"+pos3.x+"px;height:1px;width:1px");this.ad=document.getElementById("adlPPix4");this.ad.setAttribute("style",
"position:absolute;top:"+pos4.y+"px;left:"+pos4.x+"px;height:1px;width:1px")},U=function(){v=document.body.clientHeight||window.innerHeight;w=document.body.clientWidth||window.innerWidth},S=function(a){(10>=v||10>=w)&&U();var b={x:w/2-1,y:v/2-1},c={x:w*Q+1,y:v*(1-Q)-1},e={x:w/2+1,y:v/2+1},f={x:w*(1-Q)-1,y:v*Q+1};switch(a){case 0:return b;case 1:return c;case 2:return e;case 3:return f;default:return[]}};this.setVisibility=function(a,b,c){V=!0;10>=v||10>=w?Y():(D++,!u&&4==D&&(R=2<=B?2:0,u=!0),0==E&&
(E=new Date),0==F&&(F=new Date),a&&(B+=1),4==D&&(2<=B&&fnVisiState()?K=2:(K=0,E=new Date),$||(4<=B&&fnVisiState()?O=2:(O=0,F=new Date)),D=B=0,Y()),950<=new Date-E&&(2<=B&&fnVisiState()&&1==ba)&&(Z||(0<v&&0<w&&X(url_iab,{type:"IAB",rt:"flash"}),Z=!0),T++,n++,E=new Date),!$&&(new Date-F>=1E3*duree_activation_visi_adloox-50&&2==O&&fnVisiState()&&1==ba)&&(0<v&&0<w&&X(url_custom,{type:"custom",rt:"flash"}),$=!0))};var Y=function(){if(10>=v||10>=w){U();pos1=S(0);pos2=S(1);pos3=S(2);pos4=S(3);var a=document.getElementById("adlPPix1");
a.setAttribute("style","position:absolute;top:"+pos1.y+"px;left:"+pos1.x+"px;height:1px;width:1px;z-index:10");a=document.getElementById("adlPPix2");a.setAttribute("style","position:absolute;top:"+pos2.y+"px;left:"+pos2.x+"px;height:1px;width:1px;z-index:10");a=document.getElementById("adlPPix3");a.setAttribute("style","position:absolute;top:"+pos3.y+"px;left:"+pos3.x+"px;height:1px;width:1px;z-index:10");a=document.getElementById("adlPPix4");a.setAttribute("style","position:absolute;top:"+pos4.y+
"px;left:"+pos4.x+"px;height:1px;width:1px;z-index:10")}M("adlooxFPix1").setIFromJs(0);M("adlooxFPix2").setIFromJs(0);M("adlooxFPix3").setIFromJs(0);M("adlooxFPix4").setIFromJs(0)},C=function(h){if(!(0==v&&0==w)){var m=1<=n?2:0,m="//"+p+"/ads/iv2.php?adloox_transaction_id="+escape(c)+"&client="+escape(a)+"&banniere="+escape(b)+"&visible="+m+"&visite_id="+escape(e)+"&url="+escape(f)+"&campagne="+escape(g)+"&a_d="+escape(n)+"&p_d="+Math.round((new Date-l)/1E3)+"&browser="+R+"&editeur_id="+escape(k)+
"&size="+w+"x"+v+"&wasatf="+R+"&hash="+W+"&hash_adnxs="+P+"&anticache="+Math.floor(1E8*Math.random());"undefined"!==typeof navigator.sendBeacon&&!h?navigator.sendBeacon(m+"&beacon","true")||C(!0):(h=document.createElement("img"),h.src=m,h.width=0,h.height=0,h.style.display="none",/chrome/i.test(navigator.userAgent)||document.body.appendChild(h))}};window.addEventListener("unload",function(a){C(!1)});-1!=navigator.userAgent.indexOf("Safari")&&-1==navigator.userAgent.indexOf("Chrome")||(U(),"prerender"!==
fnPreState()&&(y(1),y(2),y(3),y(4),aa()));-1==navigator.appName.indexOf("Microsoft")&&fnPreState()}}):window["adl_J_Visi_infectiousg_"+x]=new E;"undefined"!==typeof adl_M_Visi&&(window.adl_M_Visi_infectiousg=new adl_M_Visi)})();