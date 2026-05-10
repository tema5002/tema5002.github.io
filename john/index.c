#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ends_with(const char *str, const char *suffix) {
    return strcmp(str + strlen(str) - strlen(suffix), suffix) == 0;
}

int main() {
    static const struct website {
        const char* username;
        const char* url;
    } websites[] = {
        {"tema5002", "https://tema5002.github.io"},
        {"wahplus", "https://sting.lt"},
        {"dtpls", "https://dtplsongithub.github.io/aboutme/"},
        {"slinx92", "https://slinx92.hs.vc/"},
        {"mari2", "https://marii2.duckdns.org/"} // MARI TWO?????????????
    };
    const struct post {
        const char* text;
        const char* src;
        const char* username;
        const char* time;
    } posts[] = {
        {"this is john he built the world biggest building", "../static/john/1.png", "tema5002", "2025-03-07T11:24:46.956Z"},
        {"john has invented a perpetual motion machine", "../static/john/2.png", "tema5002", "2025-03-07T13:08:18.661Z"},
        {"john has built the world smallest building", "../static/john/3.png", "tema5002", "2025-03-07T19:06:49.455Z"},
        {"john has built a square circle", "../static/john/4.png", "tema5002", "2025-03-08T07:59:11.416Z"},
        {"john has built a fiat 500", "../static/john/5.png", "wahplus", "2025-03-08T08:05:27.252Z"},
        {"john took a shit", NULL, "tema5002", "2025-03-08T13:40:38.730Z"},
        {"john built a bridge to nowhere", "../static/john/6.png", "tema5002", "2025-03-08T13:42:35.077Z"},
        {"i now have an original character", "../static/john/7.png", "tema5002", "2025-03-08T13:47:35.530Z"},
        {"john has built a house on a square circle", "../static/john/8.png", "tema5002", "2025-03-08T13:55:16.031Z"},
        {"john took another shit", NULL, "dtpls", "2025-03-08T14:03:28.465Z"},
        {"john took MY shit, thats right, he broke into MY house, then walked into MY bathroom, and then stole all of the shit from there", NULL, "slinx92", "2025-03-08T17:29:53.860Z"},
        {"john decided to swim on a chair", "../static/john/9.png", "tema5002", "2025-03-08T17:30:37.460Z"},
        {"john has built a b-52 stratofortress", "../static/john/10.png", "wahplus", "2025-03-09T05:57:00.854Z"},
        {"john has built a john", "../static/john/11.png", "mari2", "2025-03-09T05:58:45.220Z"},
        {"the 2 johns have built 2 more johns", "../static/john/12.png", "wahplus", "2025-03-09T06:00:06.976Z"},
        {"oh fuck they're multiplying", "../static/john/13.png", "mari2", "2025-03-09T06:00:36.430Z"},
        {"uhh ok guys how do we stop them", "../static/john/14.png", "wahplus", "2025-03-09T06:02:16.224Z"},
        {"idk", "../static/john/15.png", "mari2", "2025-03-09T06:03:41.412Z"},
        {"it doesnt look like theyre stopping anytime soon", "../static/john/16.png", "wahplus", "2025-03-09T06:05:03.217Z"},
        {"john has just invented the john clone killer 9000", "../static/john/17.png", "mari2", "2025-03-09T06:10:50.154Z"},
        {"john has just invented loss", "../static/john/18.png", "mari2", "2025-03-09T06:12:47.596Z"},
        {"john subscribed to yahiamice", "../static/john/19.png", "tema5002", "2025-03-09T10:20:42.386Z"},
        {"john invented napkins", "../static/john/20.png", "dtpls", "2025-03-09T10:23:35.040Z"},
        {"john went to krusty krab", "../static/john/21.png", "tema5002", "2025-03-09T10:26:16.987Z"},
        {"john has just invented unimeter but sane", "../static/john/22.png", "mari2", "2025-03-09T21:37:30.831Z"},
        {"john uninstalled windows 11 from his computer and made his own operating system johnlux", "../static/john/23.png", "tema5002", "2025-03-10T12:29:00.393Z"},
        {"john has lamp is hostage in my basement btw tema5002 is asexual", "../static/john/24.png", "mari2", "2025-03-11T12:41:34.897Z"},
        {"john just created this song!!<br>no this isnt just cascade slowed down idk what youre talking about", "../static/john/johns new song!!!1.mp3", "slinx92", "2025-03-11T12:47:19.124Z"},
        {"john found oil on the world biggest building", "../static/john/25.png", "tema5002", "2025-03-11T12:55:53.977Z"},
        {"the us goverment took it away", "../static/john/26.png", "tema5002", "2025-03-11T12:56:49.578Z"},
        {"they paid him though wait what the fuck john what have you done", "../static/john/27.png", "tema5002", "2025-03-11T12:58:10.409Z"},
        {"john had to pay taxes for oil now he has no money", "../static/john/26.png", "tema5002", "2025-03-11T12:59:15.333Z"},
        {"john turned the world biggest building into the world biggest gun and now gonna rob the white house", "../static/john/28.png", "tema5002", "2025-03-11T13:02:29.745Z"},
        {"john got his oil back", "../static/john/29.png", "tema5002", "2025-03-11T13:05:37.193Z"},
        {"John John Cannon invented the John Cannon", "../static/john/30.png", "TheRedBlueCube2", "2025-03-12T13:19:24.617Z"},
        {"john opened a fridge", "../static/john/31.png", "tema5002", "2025-03-12T16:14:30.438Z"},
        {"there is no john take off your pants", "../static/john/32.png", "tema5002", "2025-03-13T12:23:29.190Z"},
        {"hello fellow kids this is me the only and real john", NULL, "john", "2025-03-13T15:36:31.559Z"},
        {"john made a country and idfk how is it called systemd is still running", "../static/john/33.png", "john", "2025-03-13T15:50:16.733Z"},
        {"john learnt how to breathe underwater and found a jellyfish", "../static/john/34.png", "tema5002", "2025-03-14T18:33:57.120Z"},
        {"john made unreal engine 7 on his computer", "../static/john/35.png", "tema5002", "2025-03-14T20:08:39.709Z"},
        {"JOHN IS MISSING", "../static/john/36.png", "mari2", "2025-03-15T18:07:32.720Z"},
        {"hello chat<br>you know how i took a shit right<br>i finally wiped my ass<br>i am back", NULL, "john", "2025-03-15T18:22:20.886Z"},
        {"OH NO JOHN IS LOCKED INSIDE PRISON!!!! WE NEED TO FIND A WAY TO BREAK HIM OUT!!", "../static/john/37.png", "BobMaster69", "2025-03-15T21:13:23.156Z"},
        {"john downloaded cheats on real life (trust me) to see what will happen if he explodes 100k tnt", "../static/john/38.png", "tema5002", "2025-03-16T07:47:35.162Z"},
        {"The cake recipe was a lie!!! Fortunately we got a key out of it and now john is free.. yay", "../static/john/39.png", "BobMaster69", "2025-03-16T17:03:59.205Z"},
        {"John has just made a machine that turns fish into salmon", "../static/john/40.png", "mari2", "2025-03-24T12:11:49.834Z"},
        {"we appreciate your enthusiasm but unfortunately your mother is John", NULL, "mari2", "2025-04-01T11:40:29.078Z"},
        {"my name is john and i invented water", "../static/john/41.png", "john", "2025-04-14T13:18:16.143Z"},
        {"John's brother jnoh has invented the piss shower", NULL, "mari2", "2025-10-06T14:50:39.172Z"},
        {"john has returned and turned jnoh's piss shower into a fire shower", "../static/john/42.png", "mari2", "2025-10-06T15:02:24.413Z"},
        {"john has built an extremely hyper super mega max ultrawide monitor", "../static/john/43.png", "mari2", "2025-10-12T02:07:33.955Z"},
        {"my name is john and i invented lemonade this time<br>totally trust", "../static/john/44.png", "john", "2026-01-07T09:31:02.126Z"},
        {"john has just uninvented unimeter but sane", "../static/john/45.png", "tema5002", "2026-01-10T20:44:17.753Z"},
        {"john has applied to the forklift company to become forklift certified", "../static/john/46.png", "tema5002", "2026-01-17T11:51:21.150Z"},
        {"john built the first ever forklift that does not need electricity using the magic of forkliftium", "../static/john/47.png", "tema5002", "2026-01-17T12:00:03.467Z"},
        {"the ceo of forklift took down john's forklift and he cannot use or sell it now", "../static/john/48.png", "tema5002", "2026-01-17T12:12:34.803Z"},
        {"John stole a VLC and 37 construction signs from the ceo of forklift and now plans on doing revenge", "../static/john/49.png", "tema5002", "2026-01-17T12:13:45.378Z"},
        {"John has built a construction sign launcher<br>also apparently this sign is very electrical and therefore more dangerous", "../static/john/50.png", "tema5002", "2026-01-17T12:34:42.938Z"},
        {"hi i am too lazy to make new lore so Would you pull the lever from john to the CEO of Forklift", "../static/john/51.png", "tema5002", "2026-01-17T17:12:56.740Z"},
        {"so uhh basically john's forklift is so revolutionary that the wheels are decorations and it is able to fly and no one was hurt", NULL, "tema5002", "2026-01-18T17:14:24.859Z"},
        {"John built Gravity 2.0 machine with complex numbers and now he is flying to moon", "../static/john/52.png", "tema5002", "2026-02-10T18:12:36.795Z"},
{"Nice!!!!!!!!!!!!!!!<br>"
"This holds no great and unique john lore value I just felt like drawing this<br>"
"And I think it is Nice!!!!!!!!!!!!<br>"
"They are on the world's biggest buildings built by john the inventor<br>"
"And this is a new character called the vlc john<br>"
"He has VLC on his head<br>"
"Also john the inventor is so cool they managed to survive the lack of oxygen and radiation in space<br>"
"Truly an inventor", "../static/john/nice.png", "tema5002", "2026-03-18T18:55:27.720Z"},
        {"john invented apficator", "../static/john/53.png", "tema5002", "2026-04-08T09:06:49.308Z"},
        {"Chat is this john in GIMP dark theme reference", "../static/john/54.png", "tema5002", "2026-04-25T18:11:02.303Z"},
        {"johns discovered the johnverse", "../static/john/johnverse.png", "tema5002", "2026-05-10T16:59:52.795Z"}
    };

    printf(
"<!doctype html>"
"<html lang=\"en\">"
    "<head>"
        "<meta charset=\"UTF-8\">"
        "<meta name=\"darkreader\" content=\"no-invert\">"
        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
        "<title>john lore</title>"
        "<link rel=\"stylesheet\" href=\"../style.css\">"
        "<style>"
"#john {"
    "display: block;"
    "text-align: center;"
"}"

"#john img {"
    "height: 512px;"
"}"

"#john note {"
    "display: inline-block;"
    "font-style: italic;"
    "color: #a0a0a0;"
"}"
        "</style>"
    "</head>"
    "<body>"
        "<header>"
            "<h1>john lore<span class=\"blink\">_</span></h1>"
            "<p>I don't even know what to tell you here</p>"
            "<p>If you are a random visitor then enjoy this page</p>"
            "<div class=\"abutton-group\">"
                "<a href=\"..\" class=\"abutton\">go back</a>"
            "</div>"
        "</header>"
    "<div id=\"john\">");
    for (int p = 0; p < sizeof(posts)/sizeof(posts[0]); p++) {
        printf("<h2>%s</h2>", posts[p].text);

        if (posts[p].src != NULL) {
            if (ends_with(posts[p].src, ".png")) {
                printf("<img src=\"%s\"/>", posts[p].src);
            }
            else if (ends_with(posts[p].src, ".mp3")) {
                printf("<audio src=\"%s\" controls></audio>", posts[p].src);
            }
        }

        const char* website_url = NULL;
        for (int i = 0; i < sizeof(websites)/sizeof(websites[0]); i++) {
            if (strcmp(websites[i].username, posts[p].username) == 0) {
                website_url = websites[i].url;
            }
        }

        printf("<p><note>posted by ");
        if (website_url != NULL) {
            printf("<a href=\"%s\">%s</a>", website_url, posts[p].username);
        }
        else {
            printf("%s", posts[p].username);
        }
        printf(" at <span id=\"time\">%s</span></note></p>", posts[p].time);
    }
    printf("<script>document.querySelectorAll('span[id]').forEach(x => {x.innerHTML = new Date(x.innerHTML).toLocaleString();})</script>");
    printf("</div></body></html>");

    return 0;
}