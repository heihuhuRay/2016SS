(function(){var k=this,l=function(a,g){var h=a.split("."),d=k;h[0]in d||!d.execScript||d.execScript("var "+h[0]);for(var c;h.length&&(c=h.shift());)h.length||void 0===g?d=d[c]?d[c]:d[c]={}:d[c]=g};var m=function(a,g){for(var h in a)if(g.call(void 0,a[h],h,a))return!0;return!1};var n=function(a){return(/(?:video_id|v)=([a-zA-Z0-9_-]{11})/.exec(a)||["",""])[1]},p=function(a){return a.replace(/^0x/,"#")},q=function(a){return m(a,function(a,h){var d;if(d="@"!=h[0]&&null!=a&&""!==a)d=typeof a,d=!("object"==d&&null!=a||"function"==d)||q(a);return d&&a!==[]})},r=function(a,g){q(a)&&g.push(a)};
l("studioinnovation.layouts.lightbox.tetris.gdnAdapter.translate",function(a){for(var g={"@type":"root",tetris:{"@type":"Creative",customInvites:{"@type":"CustomInvites","160x600":a("tetris-customInvites-160x600"),"300x250":a("tetris-customInvites-300x250"),"320x50":a("tetris-customInvites-320x50"),"728x90":a("tetris-customInvites-728x90"),"120x600":a("tetris-customInvites-120x600"),"200x200":a("tetris-customInvites-200x200"),"250x250":a("tetris-customInvites-250x250"),"300x600":a("tetris-customInvites-300x600"),
"320x100":a("tetris-customInvites-320x100"),"336x280":a("tetris-customInvites-336x280"),"468x60":a("tetris-customInvites-468x60"),"580x400":a("tetris-customInvites-580x400"),"970x90":a("tetris-customInvites-970x90"),"970x250":a("tetris-customInvites-970x250")},customHeaders:{"@type":"CustomHeaders","350x75":a("tetris-customHeaders-350x75"),"900x125":a("tetris-customHeaders-900x125"),"1200x150":a("tetris-customHeaders-1200x150")},common:{"@type":"Common",logo:a("tetris-common-logo"),demoId:a("tetris-common-demoId"),
theme:a("tetris-common-theme"),googleFontName:a("tetris-common-googleFontName"),accentColor:p(a("tetris-common-accentColor")),backgroundColor:p(a("tetris-common-backgroundColor")),backgroundFadeOpacity:parseFloat(a("tetris-common-backgroundFadeOpacity")),bordered:!0,logoHref:a("tetris-common-logoHref"),fontLockerFontName:a("tetris-common-fontLocker-fontName"),captions:[]},assets:{"@type":"Assets",cards:[]}}},h=g.tetris.common.captions,d=g.tetris.assets.cards,c=0;10>c;c++){r({"@type":"Message",text:a("tetris-common-caption"+
c+"Message-text")},h);r({"@type":"Cta",text:a("tetris-common-caption"+c+"Cta-text"),href:a("tetris-common-caption"+c+"Cta-href")},h);var b=a("tetris-assets-card"+c+"Video-videoUrl");r({"@type":"VideoAsset",videoId:n(b),videoUrl:b,image:a("tetris-assets-card"+c+"Video-image")},d);for(var e=[],f="tetris-assets-card"+c+"ImageGallery",b=0;10>b;b++)r({"@type":"ImageGalleryImage",image:a(f+"-image"+b+"-image"),title:a(f+"-image"+b+"-title"),text:a(f+"-image"+b+"-text"),cta:a(f+"-image"+b+"-cta"),href:a(f+
"-image"+b+"-href")},e);r({"@type":"ImageGalleryAsset",images:e},d);if("true"==a("tetris-assets-card"+c+"ProductGallery-insert")){e=[];f="tetris-assets-cardXProductGallery";for(b=0;30>b;b++)r({"@type":"ProductGalleryProduct",image:a(f+"-product"+b+"-imageUrl"),title:a(f+"-product"+b+"-name"),text:a(f+"-product"+b+"-description"),price:a(f+"-product"+b+"-price"),href:a(f+"-product"+b+"-url")},e);r({"@type":"ProductGalleryAsset",products:e},d)}if(a("tetris-assets-card"+c+"Map-tableId")||"true"==a("tetris-assets-card"+
c+"Map-insert")){f=[];if("true"==a("tetris-assets-card"+c+"Map-insert"))for(e=k.Enabler.getParameter("LOCATION_EXTENSION_DATA")||[],b=0;b<e.length;b++)r({"@type":"MapLocation",latitude:e[b].latitude,longitude:e[b].longitude,address:e[b].address,name:e[b].name||"",featureId:e[b].featureId||"",phoneNumber:e[b].phoneNumber||"",mapImageUrlSmall:e[b].mapImageUrlSmall||"",mapImageUrlBig:e[b].mapImageUrlBig||"",exitUrlPlace:e[b].exitUrlPlace||"",exitUrlDirections:e[b].exitUrlDirections||""},f);r({"@type":"MapAsset",
tableId:a("tetris-assets-card"+c+"Map-tableId"),locations:f,radius:parseFloat(a("tetris-assets-card"+c+"Map-radius")),startingAddress:a("tetris-assets-card"+c+"Map-startingAddress")},d)}}return g});
l("studioinnovation.layouts.lightbox.tetris.gdnAdapter.translateLight",function(a){return{"@type":"root",tetris:{"@type":"Creative",customInvites:{"@type":"CustomInvites","160x600":"","300x250":"","320x50":"","728x90":"","120x600":"","200x200":"","250x250":"","300x600":"","320x100":"","336x280":"","468x60":"","580x400":"","970x90":"","970x250":""},customHeaders:{"@type":"CustomHeaders","350x75":"","900x125":"","1200x150":""},common:{"@type":"Common",logo:"",demoId:"",theme:"light",googleFontName:"",
accentColor:"#e52d27",backgroundColor:"#ffffff",backgroundFadeOpacity:100,bordered:!0,logoHref:"",fontLockerFontName:"",captions:[{"@type":"Message",text:a("headline")},{"@type":"Message",text:a("description")}]},assets:{"@type":"Assets",cards:[{"@type":"VideoAsset",videoId:n(a("videoUrl")),videoUrl:a("videoUrl"),image:""}]}}}});
l("studioinnovation.layouts.lightbox.tetris.gdnAdapter.translateFromEnablerParams",function(a){return JSON.stringify(a(function(a){a=k.Enabler.getParameter(a);return null!=a?a:""}))});l("studioinnovation.layouts.lightbox.tetris.gdnAdapter.translateFromDataObject",function(a,g){return a(function(a){return null!=g[a]?g[a]:""})});})();
