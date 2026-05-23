#!/usr/bin/env bash
# Re-run sespec_no_repair (TRUE: refine_count=0) × gpt-5 on the 322 cases that
# failed in the original 20260516 4-variant run.
#
# CAUTION: the earlier 20260517_220809 and 221025 dirs ran with refine=3 because
# they were launched via CLI without injecting sespec_no_repair into PRESETS, so
# sespec_matrix.py silently fell back to sespec_default settings. This script
# uses the python -c pattern to inject the preset correctly.
#
# Usage:
#   OPENAI_API_KEY=... ./rerun_no_repair_gpt5_correct.sh
#
# Optional:
#   WORKERS=30
set -u
REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
TS="$(date +%Y%m%d_%H%M%S)"
MATRIX_ROOT="${SRC}/results/matrix_runs/${TS}_rerun_no_repair_gpt5_TRUE_refine0"
LOG_DIR="${MATRIX_ROOT}/_runner_logs"
WORKERS="${WORKERS:-30}"

mkdir -p "${LOG_DIR}"
export PATH="/home/yangfp/.opam/default/bin:${PATH}"
if [[ -z "${OPENAI_API_KEY:-}" ]]; then
    echo "OPENAI_API_KEY is not set" >&2; exit 1
fi

cd "${SRC}"

# 322 cases that failed in the 20260516 gpt-5 sespec_no_repair run.
CASES=$(cat <<'CASELIST'
0
1
2
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
36
38
39
40
41
42
43
44
45
46
48
49
50
53
55
56
58
60
61
63
66
72
73
75
76
85
89
90
91
101
102
104
105
106
107
110
111
112
113
114
119
120
121
122
123
124
125
126
127
133
134
135
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
183
184
185
186
187
188
189
191
192
193
194
195
197
198
199
200
201
203
205
206
207
209
210
212
213
214
215
216
217
218
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
336
337
338
339
340
341
342
343
344
345
346
347
348
349
350
352
353
354
355
356
357
358
359
360
362
363
365
366
367
368
369
370
371
372
373
374
375
376
377
378
379
380
381
382
383
384
385
386
387
388
390
391
392
393
394
395
396
397
398
399
CASELIST
)

NUM_CASES=$(echo "${CASES}" | tr ' ' '\n' | grep -c '^[0-9]')
RUN_LOG="${LOG_DIR}/rerun_no_repair_gpt5_TRUE_refine0.log"

echo "Matrix root : ${MATRIX_ROOT}"
echo "Cases       : ${NUM_CASES}   Model: gpt-5   Label: sespec_no_repair (refine=0)   Workers: ${WORKERS}"
echo "Log         : ${RUN_LOG}"
echo

"${PY}" -c "
import sys
import sespec_matrix as m
# CRITICAL: inject the preset so sespec_matrix doesn't silently fall back to sespec_default (refine=3)
m.PRESETS['sespec_no_repair'] = dict(m.PRESETS['sespec_default'], refine_count=0)
print('[verify] sespec_no_repair preset =', m.PRESETS['sespec_no_repair'])
sys.argv = [
    'sespec_matrix.py',
    '--bench', 'sespec',
    '--cases', *'''${CASES}'''.split(),
    '--models', 'gpt-5',
    '--labels', 'sespec_no_repair',
    '--workers', '${WORKERS}',
    '--matrix-root', '${MATRIX_ROOT}',
]
raise SystemExit(m.main())
" 2>&1 | tee "${RUN_LOG}"

echo
echo "===== DONE ${MATRIX_ROOT} ====="
