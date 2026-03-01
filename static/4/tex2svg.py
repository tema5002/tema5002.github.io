import matplotlib.pyplot as plt
import matplotlib.font_manager as fm

#fm.fontManager.addfont("korabliki.ttf")
#fn = fm.FontProperties(fname="korabliki.ttf").get_name()
fn = "Serif"
plt.rcParams.update({
    'font.family': fn,
    'mathtext.fontset': 'custom',
    'mathtext.it': f'{fn}:italic',
    'mathtext.rm': fn,
    'mathtext.tt': fn,
    'mathtext.bf': f'{fn}:bold',
    'mathtext.cal': fn,
    'mathtext.sf': fn,
})

kreis = [
    r"1 = \frac{4}{4}",
    r"2 = \sqrt{4}",
    r"3 = 4-\frac{4}{4} = \frac{4!}{4\sqrt{4}} = \log_{\sqrt{4}}(4\sqrt{4})",
    r"4 = 4",
    r"5 = \frac{\sqrt{4}}{.4}",
    r"6 = \frac{4!}{4}",
    r"7 = \frac{4!+4}{4}",
    r"8 = 4\sqrt{4}",
    r"9 = \frac{4-.4}{.4}",
    r"10 = \frac{4}{.4}",
    r"11 = \frac{44}{4}",
    r"12 = \frac{4!}{4}",
    r"13 = \frac{4!+\sqrt{4}}{\sqrt{4}}",
    r"14 = \frac{4!+4}{\sqrt{4}}",
    r"15 = \frac{4!}{4\times.4} = \frac{4+\sqrt{4}}{.4}",
    r"16 = 4^{\sqrt{4}} = 4\times 4",
    r"17 = 4^{\sqrt{4}}+\frac{4}{4} = \frac{44+4!}{4}",
    r"18 = 4^{\sqrt{4}}+\sqrt{4} = 4!-\frac{4!}{4}",
    r"19 = 4!-\frac{\sqrt{4}}{.4}",
    r"20 = \frac{4^4}{4}-44 = \frac{4\sqrt{4}}{.4} = 44-4! = 4!-4",
    r"21 = \frac{44-\sqrt{4}}{\sqrt{4}} = \lfloor\sqrt{444}\rfloor",
    r"22 = \frac{44}{\sqrt{4}}",
    r"23 = 4!-\frac{4}{4}",
    r"24 = 4!",
    r"25 = \frac{4}{.4\times.4} = 4!+\frac{4}{4} = \frac{4!-4}{.4\times\sqrt{4}}",
    r"26 = 4!+\sqrt{4}",
    r"27 = 4!+\sqrt{4}+\frac{4}{4}",
    r"28 = 4!+4=4^{\sqrt{4}}\sqrt{4}-4",
    r"29 = \frac{4^{\sqrt{4}}-4.4}{.4}",
    r"30 = \frac{4!}{.4\sqrt{4}} = 4!+\frac{4!}{4}",
    r"31 = \frac{4^{\sqrt{4}}-4+.4}{.4} = 4!+\frac{4!+4}{4}",
    r"32 = 4^{\sqrt{4}}\sqrt{4} = 44-\frac{4!}{\sqrt{4}}",
    r"33 = 4!+\frac{4-.4}{.4} = 44-\frac{44}{4}",
    r"34 = \frac{44+4!}{\sqrt{4}} = 44-\frac{4}{.4}",
    r"35 = 44+\frac{.4-4}{.4} \frac{4!+4}{.4\sqrt{4}}",
    r"36 = \frac{4!+4}{4\sqrt{4}} = \frac{4!\times4!}{4\times4} = 4!\sqrt{4} - \frac{4!}{\sqrt{4}} = 4\times\frac{4!-.4}{.4}=44-4\sqrt{4} = 44 - 4\sqrt{4} = \frac{4!}{4}^{\sqrt{4}}",
    r"37 = 44-4-4+\frac{4}{4} = 4!+\frac{4!+\sqrt{4}}{\sqrt{4}}",
    r"38 = 44-4-\sqrt{4} = 4!\sqrt{4}-\frac{4}{.4} = 44-\frac{4!}{4}",
    r"39 = 44-\frac{\sqrt{4}}{.4}",
    r"40 = 44-4 = \frac{4\times4}{.4} = \frac{4^{4}}{4}-4!",
    r"41 = \frac{4\times4+.4}{.4}",
    r"42 = 44-\sqrt{4}",
    r"43 = 44-\frac{4}{4}",
    r"44 = 44",
    r"45 = 44+\frac{4}{4}",
    r"46 = 4!\sqrt{4}-\sqrt{4} = 44+\sqrt{4}",
    r"47 = 44+\sqrt{4}+\frac{4}{4}",
    r"48 = 44+4=4!\sqrt{4}",
    r"49 = 44+\frac{\sqrt{4}}{.4}",
    r"50 = \frac{44-4}{.4\sqrt{4}} = \frac{4\times4+4}{.4} = 44+4+\sqrt{4} = \frac{4\sqrt{4}}{.4\times4} = 44+\frac{4!}{4} = 4!\sqrt{4}+\sqrt{4} = \frac{4!-4}{.4}"
]

for i, k in enumerate(kreis):
    fig, ax = plt.subplots()
    fig.patch.set_facecolor('none')
    text = ax.text(0, 0, f'${k}$', fontsize=48, ha='left', va='bottom', color='white')
    ax.set_axis_off()
    fig.canvas.draw()
    bbox = text.get_window_extent()
    fig.set_size_inches(bbox.width/fig.dpi, bbox.height/fig.dpi)
    fig.subplots_adjust(left=0, bottom=0, right=1, top=1, wspace=0, hspace=0)
    plt.savefig(f"{i+1}.svg", format='svg', bbox_inches='tight', pad_inches=0)
    plt.close()