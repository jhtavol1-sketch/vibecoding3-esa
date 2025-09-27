<!-- Chosen Palette: Urgent Analytics (based on Energetic & Playful, adapted for seriousness) -->
<!-- Application Structure Plan: A top-to-bottom narrative structure. It starts with high-impact summary cards (the "what"), dives into the core problems with detailed charts (revenue decline, customer churn, marketing failure - the "why"), and concludes with actionable recommendations (the "how"). This tells a clear, compelling story for decision-makers. -->
<!-- Visualization & Content Choices: 1. KPIs (Inform) -> Large text cards -> Immediate impact. 2. Revenue/Profit (Change) -> Combined Bar/Line Chart -> Shows relationship between volume and efficiency decline. 3. Customers/AOV (Compare) -> Combined Bar/Line Chart -> Visually isolates customer churn as the root cause by contrasting it with stable AOV. 4. Ad Spend/ROI (Compare) -> Combined Bar/Line Chart -> Creates a dramatic "X" shape to highlight the core problem of inefficient spending. All charts use Chart.js on Canvas. -->
<!-- CONFIRMATION: NO SVG graphics used. NO Mermaid JS used. -->
<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>2025년 상반기 카페 운영 위기 진단 대시보드</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js@4.4.3/dist/chart.umd.min.js"></script>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+KR:wght@400;700;900&display=swap" rel="stylesheet">
    <style>
        body { font-family: 'Noto Sans KR', sans-serif; }
        .chart-container {
            position: relative;
            width: 100%;
            max-width: 800px;
            height: 350px;
            margin-left: auto;
            margin-right: auto;
        }
        @media (min-width: 768px) {
            .chart-container { height: 400px; }
        }
        .kpi-card { transition: transform 0.3s ease, box-shadow 0.3s ease; }
        .kpi-card:hover { transform: translateY(-5px); box-shadow: 0 10px 15px -3px rgba(0, 0, 0, 0.1), 0 4px 6px -2px rgba(0, 0, 0, 0.05); }
    </style>
</head>
<body class="bg-gray-100 text-gray-800">

    <!-- Header -->
    <header class="bg-white shadow-md">
        <div class="max-w-7xl mx-auto py-8 px-4 sm:px-6 lg:px-8 text-center">
            <h1 class="text-4xl font-black text-slate-800">2025년 상반기 운영 위기 진단 보고서</h1>
            <p class="mt-2 text-lg text-red-600 font-semibold">매출 하락과 마케팅 비효율의 악순환 분석</p>
        </div>
    </header>

    <!-- Main Content -->
    <main class="max-w-7xl mx-auto py-10 px-4 sm:px-6 lg:px-8">

        <!-- Section 1: KPI Summary -->
        <section class="mb-12">
            <h2 class="text-2xl font-bold text-slate-700 mb-6 border-l-4 border-red-500 pl-4">I. 상반기 핵심 성과 요약 (1월 대비 6월)</h2>
            <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6">
                <div class="kpi-card bg-white rounded-lg shadow p-6 text-center border-t-4 border-red-500">
                    <p class="text-md font-semibold text-gray-500">매출 변화</p>
                    <p class="text-4xl font-extrabold mt-1 text-red-600">-30.1%</p>
                    <p class="text-sm text-gray-600 mt-1">3,572만원 &rarr; 2,504만원</p>
                </div>
                <div class="kpi-card bg-white rounded-lg shadow p-6 text-center border-t-4 border-red-500">
                    <p class="text-md font-semibold text-gray-500">고객수 감소</p>
                    <p class="text-4xl font-extrabold mt-1 text-red-600">-29.9%</p>
                    <p class="text-sm text-gray-600 mt-1">매출 하락의 핵심 원인</p>
                </div>
                <div class="kpi-card bg-white rounded-lg shadow p-6 text-center border-t-4 border-orange-500">
                    <p class="text-md font-semibold text-gray-500">순이익률 하락</p>
                    <p class="text-4xl font-extrabold mt-1 text-orange-600">-2.91%p</p>
                    <p class="text-sm text-gray-600 mt-1">17.07% &rarr; 14.16%</p>
                </div>
                <div class="kpi-card bg-white rounded-lg shadow p-6 text-center border-t-4 border-red-700">
                    <p class="text-md font-semibold text-gray-500">마케팅 ROI 붕괴</p>
                    <p class="text-4xl font-extrabold mt-1 text-red-700">-303.2%p</p>
                    <p class="text-sm text-gray-600 mt-1">386.1% &rarr; 82.9%</p>
                </div>
            </div>
        </section>

        <!-- Section 2: Charts -->
        <div class="grid grid-cols-1 lg:grid-cols-2 gap-8">
            <!-- Chart 1: Revenue & Profitability -->
            <div class="bg-white rounded-lg shadow p-6">
                <h3 class="text-xl font-bold text-slate-700 mb-2">하향 곡선의 시작: 매출과 수익성 동반 하락</h3>
                <p class="text-sm text-gray-600 mb-4">6개월간 매출이 단 한 번의 반등 없이 지속적으로 하락했으며, 수익성을 나타내는 순이익률 또한 함께 악화되었습니다.</p>
                <div class="chart-container">
                    <canvas id="revenueProfitChart"></canvas>
                </div>
            </div>

            <!-- Chart 2: Customer & AOV -->
            <div class="bg-white rounded-lg shadow p-6">
                <h3 class="text-xl font-bold text-slate-700 mb-2">문제의 근원: 고객 이탈 가속화</h3>
                <p class="text-sm text-gray-600 mb-4">고객당 평균 지출액(객단가)은 안정적으로 유지되었으나, 방문 고객 수가 급격히 감소했습니다. 이는 매출 하락의 원인이 가격이나 상품이 아닌 '고객 유치 실패'에 있음을 명확히 보여줍니다.</p>
                <div class="chart-container">
                    <canvas id="customerAOVChart"></canvas>
                </div>
            </div>

            <!-- Chart 3: Marketing & ROI -->
            <div class="bg-white rounded-lg shadow p-6 lg:col-span-2">
                <h3 class="text-xl font-bold text-slate-700 mb-2">잘못된 처방: 비효율적 마케팅과 ROI 붕괴</h3>
                <p class="text-sm text-gray-600 mb-4">고객 이탈을 막기 위해 광고비를 270% 가까이 증액했으나, 투자수익률(ROI)은 오히려 수직으로 하락했습니다. 6월에는 광고비가 순이익보다 많아져, 마케팅이 수익을 창출하는 것이 아니라 잠식하는 구조가 되었습니다.</p>
                <div class="chart-container">
                    <canvas id="marketingROIChart"></canvas>
                </div>
            </div>
        </div>

        <!-- Section 3: Recommendations -->
        <section class="mt-12 bg-slate-800 text-white rounded-lg p-8">
            <h2 class="text-2xl font-bold mb-6 border-l-4 border-cyan-400 pl-4">V. 하반기 생존 전략 (H2 Action Plan)</h2>
            <p class="text-slate-300 mb-6">상반기의 악순환을 끊기 위해, 하반기는 **고객 회복**과 **마케팅 효율화**에 모든 자원을 집중해야 합니다.</p>
            <div class="grid grid-cols-1 md:grid-cols-3 gap-6">
                <div class="bg-slate-700 p-6 rounded-md">
                    <h4 class="text-lg font-bold text-cyan-400 mb-2">1. 고객 회복 전략</h4>
                    <p class="text-sm text-slate-200">신규 유입보다 **기존 고객 재방문 캠페인**에 집중하여 월 고객 수를 **최소 900명 이상**으로 회복. (매출 3,000만원 선 재돌파 목표)</p>
                </div>
                <div class="bg-slate-700 p-6 rounded-md">
                    <h4 class="text-lg font-bold text-cyan-400 mb-2">2. 마케팅 효율화</h4>
                    <p class="text-sm text-slate-200">월 광고비를 **200만원 이하로 감축**하고, ROI 목표치를 **200% 이상**으로 재설정. 고효율(1월) 채널 재분석 및 집중.</p>
                </div>
                <div class="bg-slate-700 p-6 rounded-md">
                    <h4 class="text-lg font-bold text-cyan-400 mb-2">3. 변동비 관리 강화</h4>
                    <p class="text-sm text-slate-200">원가율이 높은 메뉴를 재검토하고, 주간 단위 재고 관리 시스템을 도입하여 변동비 비율을 **43% 이하**로 관리.</p>
                </div>
            </div>
        </section>
    </main>

    <footer class="text-center py-6 text-gray-500 text-sm border-t mt-12">
        &copy; 2025년 상반기 운영 보고서. 데이터 기반 의사결정을 지원합니다.
    </footer>

    <script>
        // 보고서 내용을 CSV 로딩 없이 JavaScript 객체에 하드코딩한 데이터입니다.
        const chartData = {
            labels: ['2025-01', '2025-02', '2025-03', '2025-04', '2025-05', '2025-06'],
            revenue: [3572, 3197, 3099, 2828, 2750, 2504],
            netProfitMargin: [17.07, 15.58, 15.22, 14.73, 14.61, 14.16],
            customers: [1058, 990, 920, 850, 780, 742],
            aov: [33747, 32292, 33684, 33270, 35256, 33732],
            adCost: [158, 220, 280, 340, 390, 427],
            roi: [386.08, 226.36, 168.57, 122.35, 103.08, 82.90]
        };

        const tooltipTitleCallback = (tooltipItems) => {
            const item = tooltipItems[0];
            let label = item.chart.data.labels[item.dataIndex];
            return Array.isArray(label) ? label.join(' ') : label;
        };
        
        const defaultChartOptions = {
            responsive: true,
            maintainAspectRatio: false,
            interaction: {
                mode: 'index',
                intersect: false,
            },
            plugins: {
                legend: { position: 'top' },
                tooltip: {
                    callbacks: { title: tooltipTitleCallback }
                }
            }
        };

        // Chart 1: Revenue & Profitability (매출 및 수익성)
        new Chart(document.getElementById('revenueProfitChart'), {
            type: 'bar',
            data: {
                labels: chartData.labels,
                datasets: [{
                    label: '매출 (만원)',
                    data: chartData.revenue,
                    backgroundColor: 'rgba(59, 130, 246, 0.7)',
                    borderColor: 'rgba(59, 130, 246, 1)',
                    borderWidth: 1,
                    yAxisID: 'y',
                    order: 2,
                }, {
                    label: '순이익률 (%)',
                    data: chartData.netProfitMargin,
                    type: 'line',
                    borderColor: '#ef4444',
                    backgroundColor: '#ef4444',
                    borderWidth: 3,
                    yAxisID: 'y1',
                    order: 1,
                    tension: 0.1
                }]
            },
            options: {
                ...defaultChartOptions,
                scales: {
                    y: { type: 'linear', position: 'left', title: { display: true, text: '매출 (만원)' } },
                    y1: { type: 'linear', position: 'right', title: { display: true, text: '순이익률 (%)' }, grid: { drawOnChartArea: false } }
                }
            }
        });

        // Chart 2: Customers & AOV (고객수 및 객단가)
        new Chart(document.getElementById('customerAOVChart'), {
            type: 'bar',
            data: {
                labels: chartData.labels,
                datasets: [{
                    label: '고객수 (명)',
                    data: chartData.customers,
                    backgroundColor: 'rgba(239, 68, 68, 0.7)',
                    borderColor: 'rgba(239, 68, 68, 1)',
                    yAxisID: 'y',
                }, {
                    label: '객단가 (원)',
                    data: chartData.aov,
                    type: 'line',
                    borderColor: '#10b981',
                    backgroundColor: '#10b981',
                    borderWidth: 3,
                    yAxisID: 'y1',
                    tension: 0.1
                }]
            },
            options: {
                ...defaultChartOptions,
                scales: {
                    y: { type: 'linear', position: 'left', title: { display: true, text: '고객수 (명)' } },
                    y1: { type: 'linear', position: 'right', title: { display: true, text: '객단가 (원)' }, grid: { drawOnChartArea: false } }
                }
            }
        });

        // Chart 3: Marketing & ROI (마케팅 및 ROI)
        new Chart(document.getElementById('marketingROIChart'), {
            type: 'bar',
            data: {
                labels: chartData.labels,
                datasets: [{
                    label: '광고비 (만원)',
                    data: chartData.adCost,
                    backgroundColor: 'rgba(249, 115, 22, 0.7)',
                    borderColor: 'rgba(249, 115, 22, 1)',
                    yAxisID: 'y',
                }, {
                    label: 'ROI (%)',
                    data: chartData.roi,
                    type: 'line',
                    borderColor: '#b91c1c',
                    backgroundColor: '#b91c1c',
                    borderWidth: 3,
                    yAxisID: 'y1',
                    tension: 0.1
                }]
            },
            options: {
                ...defaultChartOptions,
                scales: {
                    y: { type: 'linear', position: 'left', title: { display: true, text: '광고비 (만원)' } },
                    y1: { type: 'linear', position: 'right', title: { display: true, text: 'ROI (%)' }, grid: { drawOnChartArea: false } }
                }
            }
        });
    </script>
</body>
</html>
