/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "-*-tamsyn-medium-*-*-*-20-*-*-*-*-*-*-*";

#define NUMCOLORS 3
static const char colors[NUMCOLORS][ColLast][8] = {
    /* border     fg          bg */
    {"#262626", "#757978", "#282828"}, /* 01 = normal */
    {"#464646", "#C1C4BC", "#282828"}, /* 02 = selected */
    {"#A04363", "#A04363", "#282828"}, /* 03 = urgent/warning */
};

static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const Bool showbar = True;       /* False means no bar */
static const Bool topbar = True;        /* False means bottom bar */

/* tagging */
static const char *tags[] = {"01", "02", "03", "04"};

static const Rule rules[] = {
    /* class         instance       title       tags mask     isfloating monitor
     */
    {"qutebrowser", NULL, NULL, 1 << 1, False, -1},
    {"firefoxdeveloperedition", NULL, NULL, 1 << 1, False, -1},
    {"Brave-browser", NULL, NULL, 1 << 2, False, -1},
    {"Steam", NULL, NULL, 1 << 2, False, -1},
    {"Slack", NULL, NULL, 1 << 2, False, -1},
    {"URxvt", "urxvt", NULL, 1 << 0, False, -1},
    {"kitty", "kitty", NULL, 1 << 0, False, -1},
    {"wezterm", "wezterm", NULL, 1 << 0, False, -1},
    {"Alacritty", "Alacritty", NULL, 1 << 0, False, -1},
    {"Emacs", NULL, NULL, 1 << 0, False, -1},
    {"URxvt", "URxvtFuzzy", NULL, 0, True, -1},
    {"URxvt", "URxvtRecord", NULL, 0, True, -1},
    {"Firefox", NULL, NULL, 1 << 8, False, -1},
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const Bool resizehints =
    False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static const char *dmenucmd[] = {
    "dmenu_run",      "-fn", "tamzen:pixelsize=20", "-nb",
    colors[0][ColBG], "-nf", colors[0][ColFG],      "-sb",
    colors[1][ColBG], "-sf", colors[1][ColFG],      NULL};
static const char *fuzzycmd[] = {"fuzzy_win", "fzf_cmd", NULL};
static const char *alsamixer[] = {"record_win", "alsamixer", NULL};
static const char *termcmd[] = {"wezterm", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"urxvt",     "-name", scratchpadname,
                                      "-geometry", "80x25", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    // { MODKEY,                       XK_r,      spawn,          {.v = dmenucmd
    // } },
    {MODKEY, XK_v, spawn, {.v = alsamixer}},
    {MODKEY, XK_space, spawn, {.v = fuzzycmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_s, togglescratch, {.v = scratchpadcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    // { MODKEY,                       XK_space,  setlayout,      {0} },
    // { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or
 * ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, toggleview, {0}},
    {ClkTagBar, 0, Button3, view, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
