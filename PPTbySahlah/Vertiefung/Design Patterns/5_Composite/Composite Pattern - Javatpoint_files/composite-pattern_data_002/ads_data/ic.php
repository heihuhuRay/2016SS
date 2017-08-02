/*************************************************************************/
//Contenu dans le JS de la page aha
/*************************************************************************/

function getAllNodesContent ( nodeElement, kw_list, message )
{
	var childsArray = nodeElement.childNodes;
	var pass = 1;
	var returnValue = "unlocked";

	for(var i = 0; i < childsArray.length; i++){
		if ( childsArray[i].nodeName != "SCRIPT" && childsArray[i].nodeName != "IFRAME" && childsArray[i].nodeName != "IMG" && childsArray[i].nodeName != "A" ) {
			/*if ( childsArray[i].nodeName == "A" )
			{
				pass = 0;
				if ( window.location.host == childsArray[i].host ){
					pass = 1;
				}
			}*/
			if ( pass == 1 ){
				if(childsArray[i].hasChildNodes()){
					returnValue = getAllNodesContent ( childsArray[i], kw_list, message );
					if ( returnValue == "locked" ){
						return "locked";
					}
				}else {
					if ( childsArray[i].nodeName == "#text" ) {
						returnValue = getAllWordsFromText ( childsArray[i].textContent, kw_list, message , "content");
						if ( returnValue == "locked" ){
							return "locked";
						}
					}
				}
			}
		}	
	}
	if ( document.body == nodeElement )
	{
	    var url_words = new Array();
            var str = document.location.href;
            var res1 = str.split("-");
            for(var i= 0; i < res1.length; i++)
            {
                var res2 = res1[i].split("_");
                for(var j= 0; j < res2.length; j++)
                {
                    var res3 = res2[j].split(".");
                    for(var k= 0; k < res3.length; k++)
                    {
                        var res4 = res3[k].split("/");
                        for(var l= 0; l < res4.length; l++)
                        {
                            var res5 = res4[l].split("&");
                            for(var m= 0; m < res5.length; m++)
                            {
                                var res6 = res5[m].split("=");
                                for(var n= 0; n < res6.length; n++)
                                {
                                    if ( typeof(res6[n]) != "undefined" && res6[n] != "" && res6[n] != "\n" ) {
                                        url_words.push(res6[n].replace("%20", " ").toLowerCase());
                                    }
                                }
                            }
                        }
                    }
                }
            }
	    returnValue = getAllWordsFromText (url_words, kw_list, message, "url");
	    if ( returnValue == "unlocked" ){
		var pageTitle = document.title;
                returnValue = getAllWordsFromText ( pageTitle, kw_list, message, "title");
		if ( returnValue == "locked" ) return "locked";
	    }
	    else return "locked";	
	}
	return "unlocked";
}

// sample mode Array contient les mots de l'url. sample en string est un bloc de test
function getAllWordsFromText (sample, array_words, message, type) 
{
	// remplacement de tous les signes de ponctuation (suite de signes ou signe isolé) par un whitespace
	if(typeof sample == "object") contenu = sample;
	else contenu = (sample.toLowerCase()).replace(/[\.,-\/#!$%\^&\*;:{}=\-_`~()]+/g, ' ');
	
	var blocking_keyword = "";
	var blocking_keywords_nb = array_words.length;

	for ( var i = 0; i < blocking_keywords_nb; i ++ ) {

                var word = array_words[i];
                var word_splitted = word.split("+");
		//tous les mots de la combinaison doivent etre dans le texte
                if( word_splitted.length > 1 ){

                    var nb_occ   = 0;
                    for ( var j = 0; j < word_splitted.length; j ++ ) {
			final_word = (typeof sample !== "object") ? " "+word_splitted[j].toLowerCase()+" " : word_splitted[j].toLowerCase();
                        nb_occ += contenu.indexOf(final_word) > 0 ? 1 : 0;
                    }
                    if(nb_occ  == word_splitted.length) blocking_keyword = word;
                }
		//mot simple
		else{
		    final_word = ( typeof sample !== "object") ? " "+word.toLowerCase()+" " : word.toLowerCase();
                    if( contenu.indexOf(final_word) >= 0 ) blocking_keyword = word;
                }

		if(blocking_keyword){
			//bloquer les publicités
			message += "&alerte_desc="+type+":"+word;
                        useFirewallForcedBlock(message);
                        return "locked";
		}
        }	
  	return "unlocked";
}	

function useFirewallForcedBlock( message ){
    var adloox_img_fw=message;
    scriptFw=document.createElement("script");
    scriptFw.src=adloox_img_fw;
    document.body.appendChild(scriptFw);
}
/*************************************************************************/
var firstNode = document.body;
var contentTab = ["4u 9525","4u9525","619","911","9525","À peine légal","a320","aaa wrestling","aanval","aardbeving","abartig","abdominal injury","abduct","abgeknallt","abgeschossen","abortion","abschaum","absturz","absturzgebiet","absturzregion","abuse","abusive","accident","aerial","aérien","affair","affaire","affäre","afghanistan","agus supriatna","ah5017","air algerie","air products","airbus","airbus a320","airbus a321-200","al-quaeda","al-sawabe","alan giese","alcohol abuse","alcohol addict","alcohol addiction","alcohol dependence","alcoholic","alcoholism","alps plane crash","alter wichser","am strich","amara culture centre","anal","andreas lubitz","andrew tosh","angegriffen","angela merkel","angriff","animal welfare","anjem choudary","anorexia","antenne","anti semitic","anti-semitic","anulingus","anus","anwar al-awlaki","apartheid","arme","arnaque","arrest","arresteren","arrêter","arsch","arschfotze","arschgesicht","arschloch","arse","arsehole","aschewolke","ash cloud","asphyxiation","ass","ass bag","ass bandit","ass banger","ass face","ass fuck","ass fucker","ass goblin","ass hat","ass head","ass hole","ass hopper","ass jacker","ass lick","ass licker","ass monkey","ass munch","ass muncher","ass nigger","ass pirate","ass shit","ass shole","ass sucker","ass wad","ass wipe","assad","assault","assbite","assclown","asscock","asscracker","asses","aswolk","atom","atombombe","atomrakete","atomunfall","atouchement","atr-72","atr42-300","attack","attacke","attaque","attentat","attouchement","aufgeilen","baby car seat ","baggage delay","baggage handling","baise","bambang soelistyo","bampot","bangkok","bangkok bomb","bankruptcy","barcelona","barcelona to duesseldorf","barcelona to düsseldorf","barcelonnette","barelylegal","basané","bashar","bastard","bataclan concert hall","bataclan theatre","battery chickens","battery farming","bdsm","beaner","beastiality","bedrog","behead","beheaded","beheading","belästigen","belästigung","belitung island","bellevue","beschiss","betrug","beurette","bewaffnet","bewaffnete","bifle","bilal hadfi","binge drink","binge drinking","bintang","bird flu","bisexualité","bisexuel","bitch","bitchass","bitches","bitchtits","bitchy","bite","bjs","black box","black boxes","blackbox","blackbox black box blackboxes","blasen","blow job","blowjob","bob patterson","bobby shepherd","boing","boîte noire","boko haram","bollocks","bollox","bom","bomb","bombardement","bombardier","bombardierung","bombe","bomben","bomber","bombes","bombing","bombs","bommen","bommenwerper","bondage","boner","boob","bougnoule","boulevard beaumarchais","boulevard voltaire","bout","brahim abdeslam","branle","branlette","brice robin","brother fucker","broutteminou","brutal","bukkake","bulgaria","bulimia","bulle","bullshit","bullying","bumble fuck","bumsen","bumslokal","burgas","burn","busen","butt","butt plug","buttfucka","buttfucker","cabu","caca","callgirl","camel toe","captain iriyanto","car seat ","carbon monoxide","carnage","carpet muncher","carsten spohr","cartoonists","catastrofe","catastrophe","catholic","cendre volcanique","charb","charlie hebdo","chasse à lhomme","cheadle","cherif hebdo","cherif kouachi","chidlom district","childline","chinc","chink","choad","chode","choking","cholera","christain","christi shepherd","christianne shepherd","christopher tehrani","christos louvros","citizens informer","clit","clit face","clit fuck","clitoris","cluster fuck","cocain","cocaine","cock","cock ass","cock bite","cock burger","cock face","cock fucker","cock head","cock jockey","cock knoker","cock master","cock mongler","cock mongruel","cock monkey","cock muncher","cock nose","cock nugget","cock shit","cock smith","cock smoker","cock sucker","cockring","cocks","cofcc","coit","cokin","cokine","columbine","compensation","condom","condoms","conservative citizens foundation","contamination","coochie","coochy","coon","cooter","copulation","coquine","costa concordia","couille","council of conservative citizens","cracker","crap","crash","crash testing","crimea","crimestoppers","cruise liner sank","cruise ship sank","cs043","cul","cum","cum bubble","cum dumpster","cum guzzler","cum jockey","cum slut","cum tart","cuni","cunnie","cunnilingus","cunnillingus","cunt","cunt face","cunt hole","cunt licker","cunt rag","cunt slut","cybersexe","dago","damage","damn","dangerous fittings","david cabanes","david hinchliff","dead","death","death row","death threats","deaths","decapitate","decapitation","décès","deep throat","deepthroat","defloration","deggo","desnudas","destroy","destruction","détournement","devastation","dewani","dewsbury factory","dick","dick bag","dick beaters","dick face","dick fuck","dick fucker","dick head","dick hole","dick juice","dick milk","dick monger","dick slap","dick sucker","dick wad","dick weasel","dick weed","dick wod","dicks","dieb","diebstahl","died","digne","dike","dildo","dildos","dimitrios xidias","dipshit","dirty","disaster","disasters","disease","disruptive passenger","diverted","djihad","dogging","dominatrix","doochbag","dood","dookie","douche","douche bag","douche waffle","dragged","dreckig","drecksack","drecksau","drogen","drowned","drug abuse","drug addict","drug addiction","drugged","drugs","drummer lee rigby","drunk","drunk female","drunken","dum shit","dumass","dumb ass","dumb fuck","dumb shit","durchsuchung","dusseldorf","dyke","e coli","eagles of death metal","earthquake","ebola","echangisme","échangiste","échangistes","ecstasy","edl","edward snowden","eier","eierlutscher","einbrecher","einbruch","einen runterholen","eingebrochen","eingestuerzt","eingestürzt","einsturz","einwanderung","einwanderungen","embraer phenom 300","emergency","emergency landing","enculé","enflure","enfoiré","english defence league","entführen","entführung","entköpfung","erawan shrine","erdbeben","erdrunken","érection","erogene","erotic","erotica","erotika","érotique","erschlagen","escort service","etchells road","ethan mcken","examen","examination","execution","executions","exhibitionist","exhibitionists","explosie","explosif","explosion","explosiv","explosive","extrem","extremer","extremisim","extremism","extremist","extremiste","extremists","ezel","facesitting","fag","fag bag","fag fucker","fag tard","faggit","faggot","faggot cock","faillissement","faillite","fanny","fantasme","fat ass","fatwa","faules miststueck","felation","fellatio","fellation","feltch","female cabin crew","femdom","ferenc illes","fesseln","festnahme","fétichisme","fetichiste","fetisch","fetish","fick dich","fick mich","ficken","fils2pute","filsdepute","fist","fisted","fisting","fkk","flagellation","flamer","flight crash","flight crashed","flight delay","flight disappeared","flight missing","flight vanished","flood","floods","flugabsturz","flugschreiber","flugzeugkatastrophe","flugzeugunglück","flugzeugunglueck","fly kick","flying kick","food poisoning","food standards","foot fetish","foreign tourists","forniquer","fotze","fouf","foufoune","foutre","france plane crash","francois hollande","fraud","fraude","free sex","french alps","french factory","frigide","fritzl","fuad basya","fucck","fuck","fuck ass","fuck bag","fuck boy","fuck brain","fuck butt","fuck face","fuck head","fuck hole","fuck in","fuck me","fuck nut","fuck nutt","fuck off","fuck stick","fuck tard","fuck up","fuck wad","fuck wit","fuck witt","fuck you","fucked","fucker","fucker sucker","fuckin","fuckin bitch","fucking","fucking bitch","fucks","fudge packer","fuk me","fuk you","fukin bitch","fullisade","fummeln","fuuck","gadaffi","gaddafi","gaggers","gang bang","gangbang","garce","gary glitter","gate j","gatwick","gay","gay ass","gay bob","gay bois","gay boys","gay fuckist","gay lord","gay tard","gay wad","gaydo gay fuck","gaza","gbh","geil","geiler bock","geiles luder","geköpft","geneva convention","genital warts","genocide","georgios chrysikopoulos","gerade mal erlaubt","gerade so legal","german wings","germanwings","gerontophobe","geschlechtsverkehr","geslacht","gewehr","giese","gilf","gloryhole","god damn","god damnit","godemichet","gooch","gook","gordon lee baum","gorgeprofonde","gouine","gouvia","gringo","group sex","guantanamo bay","gudalajara","gun","hack","hacken","hacking","haltern","haltern am see","hamas","handjob","hängetitte","harasment","harassment","hard core","hard on","hardcore","hardcore sex","harriet green","head impact","hebdo","heeb","heisse","heiβ","heiβe","hell","hell fire missiles","hellfire missiles","hentai","hercules","heroin","high risk","hijack","hijo del perro aguayo","hinunterholen","hit and run","hiv","hiv aids","hoe","holocaust","homicide","homo","homo dumbshit","homofuerst","homophobe","homophobia","homophobic","homophobique","hong kong protest","honkey","honte","hooker","hornochse","horny","hospital","hostage","hotel apologised","hotel apology","hotel bellevue","hotel food poisoning","hotel foodpoisoning","hotel illness","hotel infestation","hotel palm marina","huhrensohn","humping","hungarian slaves","hure","hurenficker","hurengesicht","hurensohn","ian watkins","illegal","illness","illnesses","illuminati","imam sadiq mosque","immigratie","immigraties","immigration","immigrations","immoral","imperial mahaba","incest","inceste","indonesia","indonesian plane","infestation","infidel","injured","interrogation","investigators","ira","iraq","isis","islam","islamic state","israel","jackass","james foley","janos orsos","jap","jayapura","jerk off","jew","jewish","jigaboo","jihad","jihadi john","jihadist","jimmy savile","jizz","john ca","john doe","john lewis car park","joko widodo","josef konig gymnasium school","jouir","jude","judenvernichtung","julian assange","jungle bunny","junglebunny","junkie","kackbratze","kama sutra","kamasutra","kanone","kantaoui beach","katastrophe","keller","ketamine","kfc","kidnap","kike","kill","killing","kills 27","king felipe","kinky","knarre","kobane","kogalymavia","kokain","kollision","kondom","konkurs","kooch","kootch","köpfen","kouachi","kozee sleep","krankheit","krankheiten","krebs","kunt","kuwait","kyke","la belle equipe","la casa nostra","la grippe aviaire","land slide","landslide","landslides","las lagunas","lawsuit","layzee sleep","le carillon","le carillon bar","le petit cambodge","leck mich","les halles","lesbian","lesbo","lewd acts","lewes crown court","lezzie","libya","life boats","life-show","lifeboats","linkstraeger","linksträger","lisle-dabeau","listeria","llinars del valles","lms","lolita","lolitas","lolittas","louis corcyra beach hotel","lucha libre","lude","luder","lufthansa","lyon attack","madeleine mccann","major bob patterson","maladie","maladies","malaria","malaysia airlines","malaysian airlines","man decapitated","mange-merde","mangemerde","manslaughter","mariano rajoy","marina bandres","martyn matthews","masochisme","massacre","massaker","massenvernichtung","masturbateur","masturbation","masturber","mated","mating","max clifford","mccain","mcfagget","mdma","medan","menace","méolans-revel","meolans-revels","merde","message for america","mh17","mh370","michael adebolajo","mick","miefen","mieser stricher","mijas golf resort","mile high club","milf","milfs","minge","misile","missbrauch","missgeburt","missonarstellung","miststück","miβbrauch","moerder","mohammed","mohammed abdeslam","mohammed rafiq","molenbeek","molest","montabour","mord","mörder","mothafucka","mother fucker","mother fuker","motherfucker","motherfucking","muff","muff diver","mugging","muhammad","munging","murder","murderer","murders","muschi","muschi lecker","muslim","mutterficker","naked","national defence league","naturism","naturist","nauwelijks legaal","nazi","ndl","necrophilia","neger","nègre","négro","neil shepherd","netanyahu","newcastle evening chronicle","news of the world","niakoué","nicola gibson","nigga","nigger","niggers","niglet","niquer","no survivors","noodgeval","north korea","notfall","nspcc","nuage de cendres","nuclear","nuclear war","nuclear weapons","nude","nudes","nudist","nudity","nuklear","nuklearwaffen","nut sack","nutsack","nympho","oasch","oben ohne","obese","obesity","obscéne","oksibil","oliver wagner","omar ismail mostefai","onanieren","onanisme","onderzoek","onethisch","ongeval","ontplofbaar","onwettig","onzin","operation yew tree","operation yewtree","opfer","opfern","oplichting","oral sex","orgasme","orgie","orgy","orsch","osama bin laden","osamabinladen","oscar gutierrez","oscar pistorius","overdose","p0rn","paederast","paedo","paedo and incest websites","paedophile","paki","panooch","panty","papua","paris attacks","paris shooting","passengers killed","patrick sonderheimer","paul bramley","peaches geldof","pecker","peckerhead","pederast","pederasty","pédophile","pédophilie","pedro aguayo ramirez","peep shows","peep-show","penis","penis fucker","penis puffer","pent house","perro aguayo jr","persian kitty","perversions","petros stoyiannos","pevers","peverser","pflaume","phallus","phone hacking","pimp","piracy","piss","piss flaps","pissed","pissed off","pisser","pissing","pissnelke","pistole","plague","plane crash","plane disappeared","plane missing","plane vanished","play boy","play mates","playboy","poisoned","poisoning","poisons","pole smoker","police","politie","polizei","polizeieinsatz","pollock","poon","poonani","poonany","poontang","porch monkey","porchmonkey","porn","porn star","porn stars","porn tube","porno","porno star","pornographic putin","pornographie","pornography","pornos","pornoszene","porteouverte","pr0n","prawit wongsuwong","prayuth chan-ocha","prépuce","prick","prise dotages forcenés","probleem","problem","problème","problemen","problèmes","problems","procreate","procreated","procreates","procreating","prophet mohammed","prostituée","prostitute","pubien","pubis","punanny","punta","pussies","pussy","pussy licking","putain","pute","puto","quarantine","queef","queer","queer bait","queer hole","queutard","racism","racisme","racist","radical preacher","rakete","ramp","rampage","rant","rape","raped","raper","rapes","raping","rapist","rassismus","rassist","rassistisch","ratchaprasong","rebel","red tube","redtube","refund","remboursement","renob","rettung","rettungseinsatz","rey mysterio jr","rhineland palatinate","richard carson","rim","rim job","rim jobs","rimjob","riot","road rage","robbery","robert shepherd","rock concert","roger alan giese","roger giese","rolf harris","rotlicht","royal kenz hotel","rückerstattung","rue de charonne","runterholen","ruski","russian investigators","ruth beatson","sack","sadist","sado","sadomaso","sadomasochisme","saeufer","saint-quentin-fallavier","salah abdeslam","salaud","salmonella","salmonelle","salmonellen","salopard","salope","saloperie","sand nigger","sandnigger","sau","saufen","säufer","saunauntersitzer","scam","scandal","scandale","scandals","scat","scatophile","schandaal","scharf","scharfe","scheide","scheise","scheisse","scheissegal","scheissen","scheisser","scheissfreundlich","scheissgesicht","scheisskerl","scheisskopf","scheiβe","schiesserei","schieβerei","schlampe","schlong","schnepfe","schockiert","schrecklich","schrullig","schuetze","schütze","schwanz","schwanz lecker","schwanz lutschen","schwanzlutscher","schweinepriest","schwuchtel","schwul","schwuler","scrote","sebastien giroux","segregationist","segregationist citizens councils of america","seifeddine rezgui","selbstbefriedigung","sentani","sentani airport","september 11","serials","serialz","severely injured","sex","sex chat","sex club","sex dvd","sex shop","sex shops","sex sites","sex toys","sex video","sex videos","sex-shop","sexaktiv","sexe","sexism","sexismus","sexist","sexshop","sexstellung","sexual","sexualität","sexually transmitted","sexuellementtransmissible","sexvideo","sexxx","sexy","sgdf","shark attack","sharon wood","she male","shelling","shia","shishkoff","shit","shit ass","shit bag","shit bagger","shit brains","shit breath","shit cunt","shit dick","shit face","shit faced","shit head","shit hole","shit house","shit spitter","shit stain","shitter","shittiest","shitting","shitty","shiz","shiznit","shooting","sickness","sinai crash","sinai desert","sinai peninsula","sinking","sitzpinkler","skandal","skank","skeet","skull fuck","slaves","sleaze blunder","slut","slutbag","sluts","smeg","smut","snatch","snuff","sodomie","sodomisé","sodomisée","sodomist","sodomists","sodomite","sodomites","sodomitic","sodomitical","sodomy","softcore","soumission","sousse","sousse beach","sperme","spermizid","spic","spick","spital","splooge","st marys sexual assault referral centre","stade de france","ständer","starb","starben","sterben","sterfgevallen","steven sotloff","sti","stirbt","stockport","stomach pump","strap on","strapon","strich","stricherin","strichjunge","strichmädchen","strippen","stripping","striptease","suicidal","suicide","suicides","sunny beach resort","supremacists","suruc","suruçmassacre","suruçtakatliamva","swift air","swiftair","swinger","swinger club","swingers","syria","taliban","talmud","tard","tease","teensex","terreur","terror","terror attack","terrorism","terrorisme","terrorismus","terrorist","terroriste","terrorists","terugbetaling","testicle","testicule","teub","teuch","teucha","the federation of socialist youth associations","the political cesspool","theft","thomas cook accident","thomas cook compensation","thomas cook illness","thomas winkelmann","threesomes","thundercunt","tignous","tijuana","tit","tit anime","tit fuck","titfuck","tits","titte","titten","titties","tittyfuck","tod","todesfälle","todesopfer","todesschuetze","topless","torrent","torture","tot","tote","tragédie","tragedies","tragedy","tragic","tragique","tragisch","tragödie","tragödien","train crash","tranny","transasia airways","transgender","transport research laboratory","transsexual","transvestit","transvestite","transvestiten","transvestites","traque","trauern","travesti","travestiet","travestieten","travestis","tremblement de terre","trigana","trigana air","truckahev","trümmer","tsunami","tunis","tunisia","tunisia attack","tunisian resort town","tussi","twat","twat waffle","twatlips","twats","twink","überdosis","überfall","überfallen","ueberfall","ueberfallen","ukraine","uncle fucker","unconscious","underage","underage girls","unethical","unethisch","unfall","unglück","unglueck","untergegangen","upskirt","upskirts","urgence","vagin","vagina","verdächtige","verdammt","verfickt","vergammelt","vergammeltes","verge","vergewaltiger","vergewaltigte","vergewaltigung","verhurt","verhurtes","vermisste","vernichtung","vernietiging","verpiss dich","verseuchen","verseuchung","versunken","verwoesting","verwüstung","vibrator","victims","viol","violeta bulc","viren","virus","viruses","virussen","visa","visas","visum","vjayjay","voegeln","vogelgriep","vogelgrippe","vögeln","volcan","volcanic","volcanic ash","volcanic eruption","volcanique","volcano","völkermord","von hinten","vorwärtseinparker","voyer web","voyeurism","voyeurisme","voyeurweb","vuil","vulkaan","vulkan","vulkanasche","vulkanisch","vulkanische as","vulve","waffe","waffen","wank","wanking","wapen","war","wares","warez","warmduscher","watchdog ","weapon","webcam","wetback","white citizens council","white nationalism","white separatism","whore","whorebag","whoreface","wichser","wilmslow road","wilmslow-handforth","wixer","wolinski","woolwich","wop","wrestler dies","x -rated","x rated","x-rated","xrated","xtreme","xxx","xxxrated","yacine sali","youpin","zerstoerung","zerstörung","zeub","zgueg","zguègue","zicke","ziekte","ziekten","zoosex","zusammensturz","zwarte doos"];
var message = "//data08.adlooxtracking.com/ads/ic2.php?fw=1&iframe=1&version=2&client=infectious&banniere=banoneinf&id_editeur=VnxCrNR8qQvJNCF6_ADLOOX_ID_20748_ADLOOX_ID_728x90_ADLOOX_ID_1_ADLOOX_ID_19236_ADLOOX_ID_66018_ADLOOX_ID_1_ADLOOX_ID_513103122_ADLOOX_ID_578045&campagne=infectiousg&methode=Netscape%3B&fai=&url_referrer=http%3A%2F%2Fwww.javatpoint.com%2Fcomposite-pattern&ads_forceblock=1&log=1&visite_id=4061023272";
getAllNodesContent ( firstNode, contentTab, message );
var adloox_impression=1;