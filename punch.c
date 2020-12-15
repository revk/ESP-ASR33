// Generate bianry output to punch lettering on to paper tape

static unsigned char const teletext[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        //  
   0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00,        // !
   0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        // "
   0x50, 0xf8, 0x50, 0x50, 0x50, 0xf8, 0x50, 0x00, 0x00,        // #
   0x20, 0x78, 0xa0, 0x70, 0x28, 0xf0, 0x20, 0x00, 0x00,        // $
   0xc0, 0xc8, 0x10, 0x20, 0x40, 0x98, 0x18, 0x00, 0x00,        // %
   0x40, 0xa0, 0x40, 0xa0, 0xa8, 0x90, 0x68, 0x00, 0x00,        // &
   0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        // '
   0x10, 0x20, 0x40, 0x40, 0x40, 0x20, 0x10, 0x00, 0x00,        // (
   0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40, 0x00, 0x00,        // )
   0x20, 0xa8, 0x70, 0xf8, 0x70, 0xa8, 0x20, 0x00, 0x00,        // *
   0x00, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x00, 0x00, 0x00,        // +
   0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x40, 0x00,        // ,
   0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,        // -
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,        // .
   0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,        // /
   0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,        // 0 (non crossed)
   0x20, 0x60, 0xa0, 0x20, 0x20, 0x20, 0xf8, 0x00, 0x00,        // 1
   0x70, 0x88, 0x08, 0x30, 0x40, 0x80, 0xf8, 0x00, 0x00,        // 2
   0x70, 0x88, 0x08, 0x30, 0x08, 0x88, 0x70, 0x00, 0x00,        // 3
   0x10, 0x30, 0x50, 0x90, 0xf8, 0x10, 0x10, 0x00, 0x00,        // 4
   0xf8, 0x80, 0xf0, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00,        // 5
   0x70, 0x88, 0x80, 0xf0, 0x88, 0x88, 0x70, 0x00, 0x00,        // 6
   0xf8, 0x08, 0x08, 0x10, 0x20, 0x40, 0x40, 0x00, 0x00,        // 7
   0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00, 0x00,        // 8
   0x70, 0x88, 0x88, 0x78, 0x08, 0x88, 0x70, 0x00, 0x00,        // 9
   0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00,        // :
   0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x20, 0x40, 0x00,        // ;
   0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00,        // <
   0x00, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00,        // =
   0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00,        // >
   0x70, 0x88, 0x08, 0x30, 0x20, 0x00, 0x20, 0x00, 0x00,        // ?
   0x70, 0x88, 0xb8, 0xa8, 0xb8, 0x80, 0x78, 0x00, 0x00,        // @
   0x70, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x00, 0x00,        // A
   0xf0, 0x88, 0x88, 0xf0, 0x88, 0x88, 0xf0, 0x00, 0x00,        // B
   0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00, 0x00,        // C
   0xf0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0, 0x00, 0x00,        // D
   0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x00, 0x00,        // E
   0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0x00, 0x00,        // F
   0x70, 0x88, 0x80, 0xb8, 0x88, 0x88, 0x78, 0x00, 0x00,        // G
   0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x00, 0x00,        // H
   0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xf8, 0x00, 0x00,        // I
   0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00,        // J
   0x88, 0x90, 0xa0, 0xc0, 0xa0, 0x90, 0x88, 0x00, 0x00,        // K
   0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf8, 0x00, 0x00,        // L
   0x88, 0xd8, 0xa8, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00,        // M
   0x88, 0xc8, 0xa8, 0xa8, 0xa8, 0x98, 0x88, 0x00, 0x00,        // N
   0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,        // O
   0xf0, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x00, 0x00,        // P
   0x70, 0x88, 0x88, 0x88, 0xa8, 0x90, 0x68, 0x00, 0x00,        // Q
   0xf0, 0x88, 0x88, 0xf0, 0xa0, 0x90, 0x88, 0x00, 0x00,        // R
   0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00, 0x00,        // S
   0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,        // T
   0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,        // U
   0x88, 0x88, 0x88, 0x88, 0x50, 0x50, 0x20, 0x00, 0x00,        // V
   0x88, 0x88, 0x88, 0x88, 0xa8, 0xa8, 0x50, 0x00, 0x00,        // W
   0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00, 0x00,        // X
   0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x20, 0x00, 0x00,        // Y
   0xf8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x00, 0x00,        // Z
   0x70, 0x40, 0x40, 0x40, 0x40, 0x40, 0x70, 0x00, 0x00,        // [
   0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00,        // backslash
   0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00, 0x00,        // ]
   0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        // ^
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,        // _
   0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        // `
   0x00, 0x00, 0x78, 0x88, 0x88, 0x98, 0x68, 0x00, 0x00,        // a
   0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x00, 0x00,        // b
   0x00, 0x00, 0x70, 0x88, 0x80, 0x88, 0x70, 0x00, 0x00,        // c
   0x08, 0x08, 0x78, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00,        // d
   0x00, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00, 0x00,        // e
   0x18, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x20, 0x00, 0x00,        // f
   0x00, 0x00, 0x78, 0x88, 0x88, 0x88, 0x78, 0x08, 0x70,        // g
   0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00,        // h
   0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00,        // i
   0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0,        // j
   0x80, 0x80, 0x88, 0x90, 0xe0, 0x90, 0x88, 0x00, 0x00,        // k
   0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00,        // l
   0x00, 0x00, 0xd0, 0xa8, 0xa8, 0xa8, 0xa8, 0x00, 0x00,        // m
   0x00, 0x00, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00,        // n
   0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,        // o
   0x00, 0x00, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x80, 0x80,        // p
   0x00, 0x00, 0x78, 0x88, 0x88, 0x88, 0x78, 0x08, 0x08,        // q
   0x00, 0x00, 0xf0, 0x88, 0x80, 0x80, 0x80, 0x00, 0x00,        // r
   0x00, 0x00, 0x78, 0x80, 0x70, 0x08, 0xf0, 0x00, 0x00,        // s
   0x40, 0x40, 0xe0, 0x40, 0x40, 0x48, 0x30, 0x00, 0x00,        // t
   0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00,        // u
   0x00, 0x00, 0x88, 0x88, 0x50, 0x50, 0x20, 0x00, 0x00,        // v
   0x00, 0x00, 0x88, 0x88, 0xa8, 0xa8, 0x50, 0x00, 0x00,        // w
   0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x00,        // x
   0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x08, 0x70,        // y
   0x00, 0x00, 0xf8, 0x10, 0x20, 0x40, 0xf8, 0x00, 0x00,        // z
   0x18, 0x20, 0x20, 0x40, 0x20, 0x20, 0x18, 0x00, 0x00,        // {
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,        // |
   0xc0, 0x20, 0x20, 0x10, 0x20, 0x20, 0xc0, 0x00, 0x00,        // }
   0x40, 0xa8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        // ~
   0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x00, 0x00,        //
};

#include <stdio.h>
#include <string.h>
#include <popt.h>
#include <err.h>

int debug = 0;

int main(int argc, const char *argv[])
{
   int repeat = 1;
   int svg = 0;
   char *data = NULL;
   size_t len = 0;
   FILE *f = open_memstream(&data, &len);
   void punch(unsigned char c) {
      if (c >= 0x80 || c < ' ')
         return;
      const unsigned char *t = teletext + 9 * (c - ' ');
      if (t[8] && !t[0])
         t++;
      for (int i = 0; i < 6; i++)
      {
         unsigned char o = 0;
         for (int b = 0; b < 8; b++)
            if (t[b] & (0x80 >> i))
               o |= (1 << b);
         fputc(o, f);
      }
   }
   {                            // POPT
      poptContext optCon;       // context for parsing command-line options
      const struct poptOption optionsTable[] = {
         { "svg", 's', POPT_ARG_NONE, &svg, 0, "SVG output" },
         { "repeat", 'n', POPT_ARG_INT, &repeat, 0, "Repeat", "N" },
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

   if (svg)
   {                            // Write SVG
      const int dpi = 1000;
      int w = (len + 9) / 10;   // Width (inches)
      printf("<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.0\" width=\"%din\" height=\"1in\" viewBox=\"0 0 %d %d\">", w, w * dpi, dpi);
      printf("<path stroke=\"black\" fill=\"#cfc\" d=\"M0 0l%d 0l0 %dl%d 0z", w * dpi, dpi, -w * dpi);
      void circle(int x, int y, int r) {
         printf("M%d %da %d %d 0 1 0 %d 0a%d %d 0 1 0 %d 0", x - r, y, r, r, r * 2, r, r, -r * 2);
      }
      int x = (w * 10 - len) * dpi / 20;
      int y = dpi * 150 / 1000;
      for (int i = -10; i < (int) len + 10; i++)
         circle(x + i * dpi / 10, y + 5 * dpi / 10, 46 * dpi / 2000);   // Feed holes
      for (int i = 0; i < len; i++)
      {
         for (int h = 0; h < 8; h++)
            if (data[i] & (1 << h))
               circle(x, y + (h + (h >= 5 ? 1 : 0)) * dpi / 10, 72 * dpi / 2000);
         x += dpi / 10;
      }
      printf("\"/>");
      printf("</svg>");
      return 0;
   }
   // Write out binary
   while (repeat--)
      fwrite(data, len, 1, stdout);

   return 0;
}
