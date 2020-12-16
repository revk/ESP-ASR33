// Generate bianry output to punch lettering on to paper tape

#define	MAXW 5
typedef const unsigned char font_t[MAXW];

font_t teletext_f[256] = {
   [' '] = { 0x00 },
   ['!'] = { 0x5F },
   ['"'] = { 0x03, 0x00, 0x03 },
   ['#'] = { 0x22, 0x7F, 0x22, 0x7F, 0x22 },
   ['$'] = { 0x24, 0x2A, 0x7F, 0x2A, 0x12 },
   ['%'] = { 0x23, 0x13, 0x08, 0x64, 0x62 },
   ['&'] = { 0x3A, 0x45, 0x5A, 0x20, 0x50 },
   ['\''] = { 0x03 },
   ['('] = { 0x1C, 0x22, 0x41 },
   [')'] = { 0x41, 0x22, 0x1C },
   ['*'] = { 0x2A, 0x1C, 0x7F, 0x1C, 0x2A },
   ['+'] = { 0x08, 0x08, 0x3E, 0x08, 0x08 },
   [','] = { 0x80, 0x60 },
   ['-'] = { 0x08, 0x08, 0x08 },
   ['.'] = { 0x40 },
   ['/'] = { 0x20, 0x10, 0x08, 0x04, 0x02 },
   ['0'] = { 0x3E, 0x41, 0x41, 0x41, 0x3E },
   ['1'] = { 0x44, 0x42, 0x7F, 0x40, 0x40 },
   ['2'] = { 0x62, 0x51, 0x49, 0x49, 0x46 },
   ['3'] = { 0x22, 0x41, 0x49, 0x49, 0x36 },
   ['4'] = { 0x18, 0x14, 0x12, 0x7F, 0x10 },
   ['5'] = { 0x27, 0x45, 0x45, 0x45, 0x39 },
   ['6'] = { 0x3E, 0x49, 0x49, 0x49, 0x32 },
   ['7'] = { 0x01, 0x61, 0x11, 0x09, 0x07 },
   ['8'] = { 0x36, 0x49, 0x49, 0x49, 0x36 },
   ['9'] = { 0x26, 0x49, 0x49, 0x49, 0x3E },
   [':'] = { 0x28 },
   [';'] = { 0x80, 0x68 },
   ['<'] = { 0x08, 0x14, 0x22, 0x41 },
   ['='] = { 0x14, 0x14, 0x14, 0x14, 0x14 },
   ['>'] = { 0x41, 0x22, 0x14, 0x08 },
   ['?'] = { 0x02, 0x01, 0x59, 0x09, 0x06 },
   ['@'] = { 0x3E, 0x41, 0x5D, 0x55, 0x5E },
   ['A'] = { 0x7E, 0x09, 0x09, 0x09, 0x7E },
   ['B'] = { 0x7F, 0x49, 0x49, 0x49, 0x36 },
   ['C'] = { 0x3E, 0x41, 0x41, 0x41, 0x22 },
   ['D'] = { 0x7F, 0x41, 0x41, 0x41, 0x3E },
   ['E'] = { 0x7F, 0x49, 0x49, 0x49, 0x41 },
   ['F'] = { 0x7F, 0x09, 0x09, 0x09, 0x01 },
   ['G'] = { 0x3E, 0x41, 0x49, 0x49, 0x7A },
   ['H'] = { 0x7F, 0x08, 0x08, 0x08, 0x7F },
   ['I'] = { 0x41, 0x41, 0x7F, 0x41, 0x41 },
   ['J'] = { 0x41, 0x41, 0x3F, 0x01, 0x01 },
   ['K'] = { 0x7F, 0x08, 0x14, 0x22, 0x41 },
   ['L'] = { 0x7F, 0x40, 0x40, 0x40, 0x40 },
   ['M'] = { 0x7F, 0x02, 0x04, 0x02, 0x7F },
   ['N'] = { 0x7F, 0x02, 0x1C, 0x20, 0x7F },
   ['O'] = { 0x3E, 0x41, 0x41, 0x41, 0x3E },
   ['P'] = { 0x7F, 0x09, 0x09, 0x09, 0x06 },
   ['Q'] = { 0x3E, 0x41, 0x51, 0x21, 0x5E },
   ['R'] = { 0x7F, 0x09, 0x19, 0x29, 0x46 },
   ['S'] = { 0x26, 0x49, 0x49, 0x49, 0x32 },
   ['T'] = { 0x01, 0x01, 0x7F, 0x01, 0x01 },
   ['U'] = { 0x3F, 0x40, 0x40, 0x40, 0x3F },
   ['V'] = { 0x0F, 0x30, 0x40, 0x30, 0x0F },
   ['W'] = { 0x3F, 0x40, 0x30, 0x40, 0x3F },
   ['X'] = { 0x63, 0x14, 0x08, 0x14, 0x63 },
   ['Y'] = { 0x03, 0x0C, 0x70, 0x0C, 0x03 },
   ['Z'] = { 0x61, 0x51, 0x49, 0x45, 0x43 },
   ['['] = { 0x7F, 0x41, 0x41 },
   ['\\'] = { 0x02, 0x04, 0x08, 0x10, 0x20 },
   [']'] = { 0x41, 0x41, 0x7F },
   ['^'] = { 0x04, 0x02, 0x01, 0x02, 0x04 },
   ['_'] = { 0x80, 0x80, 0x80, 0x80, 0x80 },
   ['`'] = { 0x01, 0x02, 0x04 },
   ['a'] = { 0x38, 0x44, 0x44, 0x24, 0x7C },
   ['b'] = { 0x7F, 0x44, 0x44, 0x44, 0x38 },
   ['c'] = { 0x38, 0x44, 0x44, 0x44, 0x28 },
   ['d'] = { 0x38, 0x44, 0x44, 0x44, 0x7F },
   ['e'] = { 0x38, 0x54, 0x54, 0x54, 0x58 },
   ['f'] = { 0x08, 0x08, 0x7E, 0x09, 0x09 },
   ['g'] = { 0x18, 0xA4, 0xA4, 0xA4, 0x7C },
   ['h'] = { 0x7F, 0x04, 0x04, 0x04, 0x78 },
   ['i'] = { 0x44, 0x7D, 0x40 },
   ['j'] = { 0x80, 0x84, 0x7D },
   ['k'] = { 0x7F, 0x10, 0x10, 0x28, 0x44 },
   ['l'] = { 0x41, 0x7F, 0x40 },
   ['m'] = { 0x7C, 0x04, 0x78, 0x04, 0x78 },
   ['n'] = { 0x7C, 0x04, 0x04, 0x04, 0x78 },
   ['o'] = { 0x38, 0x44, 0x44, 0x44, 0x38 },
   ['p'] = { 0xFC, 0x24, 0x24, 0x24, 0x18 },
   ['q'] = { 0x18, 0x24, 0x24, 0x24, 0xFC },
   ['r'] = { 0x7C, 0x04, 0x04, 0x04, 0x08 },
   ['s'] = { 0x48, 0x54, 0x54, 0x54, 0x24 },
   ['t'] = { 0x04, 0x3F, 0x44, 0x40, 0x20 },
   ['u'] = { 0x3C, 0x40, 0x40, 0x40, 0x7C },
   ['v'] = { 0x0C, 0x30, 0x40, 0x30, 0x0C },
   ['w'] = { 0x3C, 0x40, 0x30, 0x40, 0x3C },
   ['x'] = { 0x44, 0x28, 0x10, 0x28, 0x44 },
   ['y'] = { 0x1C, 0xA0, 0xA0, 0xA0, 0x7C },
   ['z'] = { 0x44, 0x64, 0x54, 0x4C, 0x44 },
   ['{'] = { 0x08, 0x36, 0x41, 0x41 },
   ['|'] = { 0x7F },
   ['}'] = { 0x41, 0x41, 0x36, 0x08 },
   ['~'] = { 0x02, 0x01, 0x02, 0x04, 0x02 },
   [''] = { 0x7F, 0x7F, 0x7F, 0x7F, 0x7F },
};

font_t alteran_small_f[256] = {
   ['0'] = { 0x78, 0xC8, 0x78 },
   ['1'] = { 0x48, 0xC0, 0x40 },
   ['2'] = { 0x48, 0xC8, 0x40 },
   ['3'] = { 0x48, 0xC8, 0x48 },
   ['4'] = { 0x58, 0xC8, 0x48 },
   ['5'] = { 0x58, 0xD8, 0x48 },
   ['6'] = { 0x58, 0xD8, 0x58 },
   ['7'] = { 0x78, 0xD8, 0x58 },
   ['8'] = { 0x78, 0xF8, 0x58 },
   ['9'] = { 0x78, 0xF8, 0x78 },
   ['A'] = { 0x28, 0x28, 0x78 },
   ['B'] = { 0x48, 0x58, 0x78 },
   ['C'] = { 0x78, 0x08, 0x78 },
   ['D'] = { 0x68, 0x78, 0x68 },
   ['E'] = { 0x78, 0x20, 0x68 },
   ['F'] = { 0x08, 0x08, 0x78 },
   ['G'] = { 0x78, 0x40, 0x58 },
   ['H'] = { 0x68, 0x28, 0x78 },
   ['I'] = { 0x48, 0x68, 0x48 },
   ['J'] = { 0x58, 0x48, 0x58 },
   ['K'] = { 0x00, 0x58, 0x78 },
   ['L'] = { 0x50, 0x78, 0x28 },
   ['M'] = { 0x58, 0x60, 0x58 },
   ['N'] = { 0x60, 0x38, 0x70 },
   ['O'] = { 0x58, 0x03, 0x68 },
   ['P'] = { 0x78, 0x00, 0x48 },
   ['Q'] = { 0x50, 0x38, 0x50 },
   ['R'] = { 0x68, 0x48, 0x68 },
   ['S'] = { 0x78, 0x10, 0x38 },
   ['T'] = { 0x68, 0x20, 0x68 },
   ['U'] = { 0x08, 0x08, 0x78 },
   ['V'] = { 0x48, 0x78, 0x78 },
   ['W'] = { 0x58, 0x30, 0x78 },
   ['X'] = { 0x78, 0x40, 0x78 },
   ['Y'] = { 0x78, 0x48, 0x18 },
   ['Z'] = { 0x68, 0x38, 0x48 },
};

font_t alteran_f[256] = {
   ['0'] = { 0x7F, 0xC3, 0x7F },
   ['1'] = { 0x43, 0xC0, 0x40 },
   ['2'] = { 0x43, 0xC3, 0x40 },
   ['3'] = { 0x43, 0xC3, 0x43 },
   ['4'] = { 0x4F, 0xC3, 0x43 },
   ['5'] = { 0x4F, 0xCF, 0x43 },
   ['6'] = { 0x4F, 0xCF, 0x4F },
   ['7'] = { 0x7F, 0xCF, 0x4F },
   ['8'] = { 0x7F, 0xFF, 0x4F },
   ['9'] = { 0x7F, 0xFF, 0x7F },
   ['A'] = { 0x33, 0x33, 0xFF },
   ['B'] = { 0xC3, 0xCF, 0xFF },
   ['C'] = { 0xFF, 0x03, 0xFF },
   ['D'] = { 0xF3, 0xFF, 0xF3 },
   ['E'] = { 0xFF, 0x30, 0xF3 },
   ['F'] = { 0x03, 0x03, 0xFF },
   ['G'] = { 0xFF, 0xC0, 0xCF },
   ['H'] = { 0xF3, 0x33, 0xFF },
   ['I'] = { 0xC3, 0xF3, 0xC3 },
   ['J'] = { 0xCF, 0xC3, 0xCF },
   ['K'] = { 0x00, 0xCF, 0xFF },
   ['L'] = { 0xCC, 0xFF, 0x33 },
   ['M'] = { 0xCF, 0xF0, 0xCF },
   ['N'] = { 0xF0, 0x3F, 0xFC },
   ['O'] = { 0xCF, 0x00, 0xF3 },
   ['P'] = { 0xFF, 0x00, 0xC3 },
   ['Q'] = { 0xCC, 0x3F, 0xCC },
   ['R'] = { 0xF3, 0xC3, 0xF3 },
   ['S'] = { 0xFF, 0x0C, 0x3F },
   ['T'] = { 0xF3, 0x30, 0xF3 },
   ['U'] = { 0x03, 0x03, 0xFF },
   ['V'] = { 0xC3, 0xFF, 0xFF },
   ['W'] = { 0xCF, 0x3C, 0xFF },
   ['X'] = { 0xFF, 0xC0, 0xFF },
   ['Y'] = { 0xFF, 0xC3, 0x0F },
   ['Z'] = { 0xF3, 0x3F, 0xC3 },
};

font_t small_f[256] = {
   ['0'] = { 0x70, 0x88, 0x88, 0x70 },
   ['1'] = { 0x88, 0xF8, 0x80 },
   ['2'] = { 0xC0, 0xA8, 0xA8, 0x90 },
   ['3'] = { 0x88, 0xA8, 0xA8, 0x50 },
   ['4'] = { 0x60, 0x50, 0xF8, 0x40 },
   ['5'] = { 0xB8, 0xA8, 0xA8, 0X48 },
   ['6'] = { 0x70, 0xA8, 0xA8, 0x40 },
   ['7'] = { 0x08, 0xC8, 0x28, 0x18 },
   ['8'] = { 0x50, 0xA8, 0xA8, 0x50 },
   ['9'] = { 0x10, 0xA8, 0xA8, 0x70 },
   ['A'] = { 0xE0, 0x50, 0x48, 0x50, 0xE0 },
   ['B'] = { 0xF8, 0xA8, 0xA8, 0xA8, 0x50 },
   ['C'] = { 0x70, 0x88, 0x88, 0x88 },
   ['D'] = { 0xF8, 0x88, 0x88, 0x88, 0x70 },
   ['E'] = { 0xF8, 0xA8, 0xA8, 0xA8, 0x88 },
   ['F'] = { 0xF8, 0x28, 0x28, 0x28, 0x08 },
   ['G'] = { 0x70, 0x88, 0x88, 0xA8, 0x60 },
   ['H'] = { 0xF8, 0x20, 0x20, 0x20, 0xF8 },
   ['I'] = { 0x88, 0xF8, 0x88 },
   ['J'] = { 0x40, 0x88, 0x78, 0x08 },
   ['K'] = { 0xF8, 0x20, 0x50, 0x88 },
   ['L'] = { 0xF8, 0x80, 0x80, 0x80, 0x80 },
   ['M'] = { 0xF8, 0x10, 0x20, 0x10, 0xF8 },
   ['N'] = { 0xF8, 0x10, 0x20, 0x40, 0xF8 },
   ['O'] = { 0x70, 0x88, 0x88, 0x88, 0x70 },
   ['P'] = { 0xF8, 0x28, 0x28, 0x28, 0x10 },
   ['Q'] = { 0x70, 0x88, 0xA8, 0x48, 0xB0 },
   ['R'] = { 0xF8, 0x28, 0x28, 0x68, 0x90 },
   ['S'] = { 0x10, 0xA8, 0xA8, 0xA8, 0x40 },
   ['T'] = { 0x08, 0x08, 0xF8, 0x08, 0x08 },
   ['U'] = { 0x78, 0x80, 0x80, 0x80, 0x78 },
   ['V'] = { 0x38, 0x40, 0x80, 0x40, 0x38 },
   ['W'] = { 0x78, 0x80, 0x60, 0x80, 0x78 },
   ['X'] = { 0x88, 0x50, 0x20, 0x50, 0x88 },
   ['Y'] = { 0x08, 0x10, 0xE0, 0x10, 0x08 },
   ['Z'] = { 0x88, 0xC8, 0xA8, 0x98, 0x88 },
};

#include <stdio.h>
#include <string.h>
#include <popt.h>
#include <ctype.h>
#include <err.h>

int debug = 0;

int main(int argc, const char *argv[])
{
   int repeat = 1;
   int gap = 5;
   int lead = 15;
   int tail = 15;
   int svg = 0;
   int space = 4;
   char *data = NULL;
   size_t len = 0;
   font_t *font = teletext_f;
   int alteran = 0;
   int small = 0;
   int zig = 0;
   int okdc4 = 0;
   int dc = 0;
   FILE *f = open_memstream(&data, &len);
   void punch(unsigned char c) {
      const unsigned char *d = font[c];
      if (!*d && isalpha(c))
         d = (void *) font[toupper(c)];
      int l = MAXW;
      while (l && !d[l - 1])
         l--;
      if (c == ' ' && l < space - 2)
         l = space - 2;         // Min space for a space (allow for the fact we add one at the end and start)
      while (l--)
         fputc(*d++, f);
      fputc(0, f);
   }

   {                            // POPT
      poptContext optCon;       // context for parsing command-line options
      const struct poptOption optionsTable[] = {
         { "svg", 's', POPT_ARG_NONE, &svg, 0, "SVG output" },
         { "repeat", 'n', POPT_ARG_INT | POPT_ARGFLAG_SHOW_DEFAULT, &repeat, 0, "Repeat", "N" },
         { "lead", 'l', POPT_ARG_INT | POPT_ARGFLAG_SHOW_DEFAULT, &lead, 0, "Lead", "N" },
         { "gap", 'g', POPT_ARG_INT | POPT_ARGFLAG_SHOW_DEFAULT, &gap, 0, "Gap", "N" },
         { "tail", 't', POPT_ARG_INT | POPT_ARGFLAG_SHOW_DEFAULT, &tail, 0, "Tail", "N" },
         { "alteran", 'A', POPT_ARG_NONE, &alteran, 0, "Ateran" },
         { "small", 'S', POPT_ARG_NONE, &small, 0, "Small" },
         { "zig-zag", 'Z', POPT_ARG_NONE, &zig, 0, "Zig-Zag" },
         { "ok-dc4", 0, POPT_ARG_NONE, &okdc4, 0, "DC4 is OK (not handled)" },
         { "dc", 0, POPT_ARG_NONE, &dc, 0, "Send DC4/DC2 start/stop" },
         { "space", 0, POPT_ARG_INT | POPT_ARGFLAG_SHOW_DEFAULT, &space, 0, "Space size", "N" },
         { "debug", 'v', POPT_ARG_NONE, &debug, 0, "Debug" },
         POPT_AUTOHELP { }
      };

      optCon = poptGetContext(NULL, argc, argv, optionsTable, 0);
      poptSetOtherOptionHelp(optCon, "text");

      int c;
      if ((c = poptGetNextOpt(optCon)) < -1)
         errx(1, "%s: %s\n", poptBadOption(optCon, POPT_BADOPTION_NOALIAS), poptStrerror(c));

      if (!poptPeekArg(optCon))
         errx(1, "Specify text");

      if (alteran && small)
         font = alteran_small_f;
      else if (alteran)
         font = alteran_f;
      else if (small)
         font = small_f;

      while (poptPeekArg(optCon))
      {
         const char *t = poptGetArg(optCon);
         while (*t)
            punch(*t++);
         if (poptPeekArg(optCon))
            punch(' ');
      }
      poptFreeContext(optCon);
   }

   fclose(f);
   if (len && !data[len - 1])
      len--;                    // Trailing end of last character

   const unsigned char zigzag[] = { 0x01, 0x02, 0x04, 0x02 };
   if (zig)
      for (int i = 0; i < len; i++)
         data[i] |= zigzag[i % 4];


   if (svg)
   {                            // Write SVG
      const int dpi = 1000;
      int w = (len + 15) / 10;  // Width (inches)
      printf("<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.0\" width=\"%din\" height=\"1in\" viewBox=\"0 0 %d %d\">", w, w * dpi, dpi);
      printf("<path stroke=\"black\" fill=\"#cfc\" d=\"M0 0l%d 0l0 %dl%d 0z", w * dpi, dpi, -w * dpi);
      void circle(int x, int y, int r) {
         printf("M%d %da %d %d 0 1 0 %d 0a%d %d 0 1 0 %d 0", x - r, y, r, r, r * 2, r, r, -r * 2);
      }
      int x = (w * 10 - len) * dpi / 20;
      int y = dpi * 100 / 1000;
      for (int i = -10; i < (int) len + 10; i++)
         circle(x + i * dpi / 10, y + 3 * dpi / 10, 46 * dpi / 2000);   // Feed holes
      for (int i = 0; i < len; i++)
      {
         for (int h = 0; h < 8; h++)
            if (data[i] & (1 << h))
               circle(x, y + (h + (h >= 3 ? 1 : 0)) * dpi / 10, 72 * dpi / 2000);
         x += dpi / 10;
      }
      printf("\"/>");
      printf("</svg>");
      return 0;
   }
   // Write out binary
   if (dc)
      fputc(0x12, stdout);      // DC2
   for (int i = 0; i < lead; i++)
      fputc(0, stdout);
   while (repeat--)
   {
      if (okdc4)
         fwrite(data, len, 1, stdout);
      else
         for (int i = 0; i < len; i++)
         {
            fputc(data[i], stdout);
            if ((data[i] & 0x7F) == 0x14)       // DC4
               fputc(0x12, stdout);     // DC2
         }
      if (repeat)
         for (int i = 0; i < gap; i++)
            fputc(0, stdout);
   }
   for (int i = 0; i < tail; i++)
      fputc(0, stdout);
   if (dc)
      fputc(0x14, stdout);      // DC4

   return 0;
}
