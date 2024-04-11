import temalib, os

with temalib.editfile("emojis_.html") as f:
    for i in os.listdir(temalib.get_folder_path(__file__, "emojis")):
        f.write(f'        <div class="emoji"><img src="emojis/{i}" alt="{i}"><p>{i[:-4]}</p></div>\n')