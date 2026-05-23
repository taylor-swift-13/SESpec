#!/usr/bin/env bash
# Re-run the 333 sespec_no_repair cases that failed on gpt-5-mini in the
# 0514 matrix run. The script:
#   (1) deletes the old (failed) per-case run subdirs in place,
#   (2) re-invokes sespec_matrix.py with the same MATRIX_ROOT so the new
#       summaries land directly under <case_id>/<new_run_id>/summary.json.
#
# After completion, MATRIX_ROOT/summary.csv only describes this rerun
# (sespec_no_repair, gpt-5-mini, the 333 reran cases). Re-aggregate the
# overall 4-variant table separately if needed.
#
# Usage:
#   OPENAI_API_KEY=... ./rerun_norepair_gpt5mini_failed.sh
#
# Optional:
#   WORKERS=24
set -u
REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
MATRIX_ROOT="${SRC}/results/matrix_runs/20260514_215427_input_sespec_4variants_3models"
TARGET_DIR="${MATRIX_ROOT}/sespec_no_repair/sespec/gpt-5-mini"
WORKERS="${WORKERS:-24}"

export PATH="/home/yangfp/.opam/default/bin:${PATH}"
if [[ -z "${OPENAI_API_KEY:-}" ]]; then
    echo "OPENAI_API_KEY is not set" >&2; exit 1
fi

if [[ ! -d "${TARGET_DIR}" ]]; then
    echo "Target dir not found: ${TARGET_DIR}" >&2; exit 1
fi

cd "${SRC}"

CASES=$(cat <<'CASELIST'
0
1
2
3
5
6
8
9
14
15
16
20
22
23
24
25
28
30
33
34
35
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
94
95
96
97
98
99
100
101
102
103
104
106
107
108
109
110
111
114
115
116
117
118
119
120
121
122
124
128
129
130
131
132
134
137
138
139
140
141
142
143
144
145
146
147
148
149
154
156
157
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
176
177
178
179
182
183
184
185
186
187
189
193
194
195
196
197
199
200
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
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
271
272
273
274
275
277
278
279
280
281
282
283
284
285
298
299
300
301
305
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
351
352
353
354
355
356
357
358
359
360
361
362
363
364
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
389
390
391
392
393
394
395
396
397
398
CASELIST
)

NUM_CASES=$(echo "${CASES}" | tr ' ' '\n' | grep -c '^[0-9]')
echo "Pre-clean: deleting failed run subdirs for ${NUM_CASES} cases under"
echo "  ${TARGET_DIR}/<case_id>/<run_id>"
for c in ${CASES}; do
    d="${TARGET_DIR}/${c}"
    if [[ -d "${d}" ]]; then
        find "${d}" -mindepth 1 -maxdepth 1 -type d -exec rm -rf {} +
    fi
done
echo "Pre-clean done."

mkdir -p "${MATRIX_ROOT}/_runner_logs"
RUN_LOG="${MATRIX_ROOT}/_runner_logs/rerun_norepair_gpt5mini_failed_$(date +%Y%m%d_%H%M%S).log"

echo "Rerun → MATRIX_ROOT: ${MATRIX_ROOT}"
echo "Cases: ${NUM_CASES}   Model: gpt-5-mini   Label: sespec_no_repair   Workers: ${WORKERS}"
echo "Log: ${RUN_LOG}"

"${PY}" -c "
import sys
import sespec_matrix as m
m.PRESETS['sespec_no_repair'] = dict(m.PRESETS['sespec_default'], refine_count=0)
sys.argv = [
    'sespec_matrix.py',
    '--bench', 'sespec',
    '--cases', *'''${CASES}'''.split(),
    '--models', 'gpt-5-mini',
    '--labels', 'sespec_no_repair',
    '--workers', '${WORKERS}',
    '--matrix-root', '${MATRIX_ROOT}',
]
raise SystemExit(m.main())
" 2>&1 | tee "${RUN_LOG}"

echo
echo "===== DONE ${MATRIX_ROOT} ====="
echo "Note: ${MATRIX_ROOT}/summary.csv now describes only this rerun batch."
echo "Re-aggregate the overall 4-variant numbers from per-case summary.json files if needed."
